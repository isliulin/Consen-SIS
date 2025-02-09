/*
 *------------------------------------------------------------
 * Project:	cagOS
 * Goal:  OS configure code.
 * Copyright (c) 2013, 2014 CAG Systems, Inc.
 *------------------------------------------------------------
 *
 *    @@@@     @@@      @@@@@       ####      ######
 *  @@       @@  @@    @@         ##    ##   ##
 * @@       @@    @@  @@   @@@@  ##      ## ######
 * @@      @@@@@@@@@@ @@    @@    ##    ##      ##
 *  @@@@@ @@@      @@@  @@@@@@      ####  #######
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable CAG license agreement.
 *
 * 1 tab == 4 spaces!
 *------------------------------------------------------------
 * modification history
 * --------------------
 * 01,Feb,2016,Ezio created
 *
 * DESCRIPTION
 * This file contains OS apis
 */

/*
 *
 * prio: 任务优先级，存在相同优先级的不同任务，应用程序看到的 prio 不是真正的prio
 * id: 任务的唯一标识，供应用使用区分任务
 *
 * stack_pos: 记录那些 tcb 和 stack 已经被使用
 * pos: 标识应用任务占用的tcb
 * tcb: os 用来标识任务，位置由 pos 来决定
 * stack: 任务栈，位置由 pos 决定,
 *
 * prio_real=prio_rts +prio_base
 * id=pos+prio_rts
 * tcb=tcb[pos]
 * stack=stack[pos]
 * stack_pos: 1=not used,0=used(为了使用 gcc 的内置函数）
 *
 */

#define  MICRIUM_SOURCE
#include <kernel/sysOs.h>
#include <kernel/sysMap.h>
#include <ppc/ppc85xx.h>
#include <libc/stdio.h>

extern void sysUsDelay(int delay);
typedef int (*FUNCPTR) (void);
extern int excVecInit (FUNCPTR * baseAddr);

#define RTS_NUM         10
#define RTS_PRIO_BASE   0 /*5*/
#define QUEUS_NUM       20
#define SEM_NUM         20
#define MUT_NUM         20
#define RTS_TASK_PRIO   1
#define OS_VERSION_STRING  "20170320"
const char version_string[] = OS_VERSION_STRING;

OS_TCB      rts_tcbs[RTS_NUM];
OS_Q        rts_msgq[QUEUS_NUM];
OS_SEM      rts_sem[SEM_NUM];
OS_MUTEX    rts_mutex[MUT_NUM];

static unsigned long stack_pos=0xffffffff; /*初始值需要体现出 os 自己的任务 or 将 rts 任务单独管理*/

void rts_var_init(void)
{
    int i=0;
    for(i=0;i<QUEUS_NUM;i++) {
        rts_msgq[i].Type = OS_OBJ_TYPE_NONE;
    }
    for(i=0;i<SEM_NUM;i++) {
        rts_sem[i].Type = OS_OBJ_TYPE_NONE;
    }
    for(i=0;i<MUT_NUM;i++) {
        rts_mutex[i].Type = OS_OBJ_TYPE_NONE;
    }
}

int os_get_prio(int id)
{
    return id&0xffff;
}

int os_get_pos(int id)
{
    return (id&0xffff0000)>>16;
}

/*
 * 创建任务
 *
 * Description: 创建一个新任务执行用户函数
 *
 * Arguments:
 *      [in]pname   任务名
 *      [in]ptask   任务函数
 *      [in]parg    函数参数
 *      [in]prio    任务优先级（可用范围1~9）
 *      [in]tq      时间片个数(为0则创建不支持时间片的rr任务)
 *      [out]err     返回操作错误码
 * Returns:
 *      创建成功返回任务id，失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
UINT32 pos = 0;
int os_create_task(char *pname, void *ptask, void *parg, int prio,unsigned int tq, unsigned int *err)
{
    if (err == NULL)
        return -1;
    
    if(prio >= RTS_NUM || prio <0)
        return -2;
    OSTaskCreate(&rts_tcbs[pos],
                 pname,
                 ptask,
                 parg,
                 prio+RTS_PRIO_BASE,
                 (CPU_STK*)(TASK_STACK_HIGH-(( pos +RTS_PRIO_BASE)*(TASK_STACK_SIZE+GAP_SIZE))),/*gcc*/
                 (TASK_STACK_SIZE/10u),
                 TASK_STACK_SIZE,
                 0,/*maximun number of messages*/
                 tq,
                 (unsigned char *)(TASK_SPESTACK_HIGH-((pos+RTS_PRIO_BASE)*(TASK_SPESTACK_SIZE+GAP_SIZE))),
                 (OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR|OS_OPT_TASK_SAVE_FP),
                 err);

    printf("####POS:%x, STACK:%x ",pos,TASK_STACK_HIGH-((pos+RTS_PRIO_BASE)*(TASK_STACK_SIZE+GAP_SIZE)));
    printf("SPESTACK:%x\n",TASK_SPESTACK_HIGH-((pos+RTS_PRIO_BASE)*(TASK_SPESTACK_SIZE+GAP_SIZE)));
    pos++;
    if (*err != OS_ERR_NONE)
        return -1;
    else {
        stack_pos &= ~(1<<pos);
        return (pos<<16)|prio;
    }
}

/*
 *
 * 删除任务
 *
 * Description: 删除指定优先级的任务
 *
 * Arguments:
 *      [in]id    任务 id 号
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功返回0，失败返回-1
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_del_task(int id,unsigned int *err)
{
    if (err == NULL)
        return -1;

    /*delete self*/
    if(id== 0xffff) {
        OSTaskDel(OSTCBCurPtr, err);
    } else {
        int pos= os_get_pos(id);
        if(pos>= RTS_NUM || pos<0)
            return -2;
        OSTaskDel(&rts_tcbs[pos], err);
    }

    if (*err != OS_ERR_NONE)
        return -1;
    else {
        return 0;
    }
}

/*
 *
 * 唤醒任务
 *
 * Description: 唤醒一个被挂起的任务
 *
 * Arguments:
 *      [in]id    任务 id 号
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功返回0，失败返回-1
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_resume_task(int id,unsigned int *err)
{
    if (err == NULL)
        return -1;

    int pos = os_get_pos(id);
    if(pos >= RTS_NUM || pos<0)
        return -2;
    OSTaskResume(&rts_tcbs[pos],err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}

/*
 *
 * 挂起任务
 *
 * Description: 挂起一个任务
 *
 * Arguments:
 *      [in]pos    任务 id 号
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功返回0，失败返回-1
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_suspend_task(int id, unsigned int *err)
{
    if (err == NULL)
        return -1;

    int pos = os_get_pos(id);
    if(pos >= RTS_NUM || pos <0)
        return -2;
    OSTaskSuspend(&rts_tcbs[pos],err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}

/*
 *
 * 修改任务时间片
 *
 * Description: 修改制定任务的时间片个数
 *
 * Arguments:
 *      [in]pos    任务 id 号
 *      [in]time_slice  要设置的时间片个数(为0 则修改任务为不支持时间片的rr 任务)
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功返回0，失败返回-1
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_task_set_ts(int id,unsigned int time_slice, unsigned int *err)
{
    if (err == NULL)
        return -1;

    int pos = os_get_pos(id);
    if(pos >= RTS_NUM || pos <0)
        return -2;
    OSTaskTimeQuantaSet(&rts_tcbs[pos],time_slice,err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}
#if 0
/*
 *
 * 向任务发送信号
 *
 * Description: 向一个任务发送信号
 *
 * Arguments:
 *      [in]pos    任务 id 号
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      返回任务当前的信号值
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
unsigned int os_task_sem_post(int id, unsigned short opt, unsigned int *err)
{
    int pos = os_get_pos(id);
    if(pos >= RTS_NUM || pos <0)
        return -2;
    return (int)OSTaskSemPost(&rts_tcbs[pos],opt,err);
}

/*
 *
 * 等待信号
 *
 * Description: 等待其它任务给自己发信号
 *
 * Arguments:
 *      [in]timeout     等待信号的超时时间(为0 则一直等待)
 *      [in]opt         选项
 *      [out]timestamp  收到信号的时间戳
 *      [out]err        返回操作错误码
 *
 * Returns:
 *      返回任务收到的信号值
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
unsigned int os_task_sem_pend(int timeout, unsigned short opt, unsigned int *err)
{
    OSTaskSemPend(timeout,opt,NULL,err);

    if (*err == OS_ERR_PEND_WOULD_BLOCK) {
        return 1;
    } else if (*err != OS_ERR_NONE) {
        return 2;
    } else {
        return 0;
    }
}

/*
 *
 * 修改信号值
 *
 * Description: 修改一个任务的信号值
 *
 * Arguments:
 *      [in]id      任务 id 号
 *      [in]cnt     新的信号值
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      新的信号值
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_task_sem_set(int id,unsigned int cnt, unsigned int *err)
{
    int pos = os_get_pos(id);
    if(pos >= RTS_NUM || pos <0)
        return -2;
    return (int)OSTaskSemSet(&rts_tcbs[pos],cnt,err);
}
#endif /*no use task sem */

/*
 *
 * 任务延时
 *
 * Description: 让当前任务让权等待一段时间
 *
 * Arguments:
 *      [in]dly     延时的 tick 数
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      新的信号值
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
void os_delay_task(int dly, unsigned int *err)
{
    OSTimeDly(dly, OS_OPT_TIME_DLY,err);
}

/*
 *
 * 等待
 *
 * Description: 让任务忙等待一段时间
 *
 * Arguments:
 *      [in]us      忙等待的微秒数
 *
 * Returns: None
 *
 *
 */
void udelay(int us)
{
    sysUsDelay(us);
}

/*
 *
 * 创建消息队列
 *
 * Description: 创建一个消息队列
 *
 * Arguments:
 *      [in]qname   消息队列名称
 *      [in]qsize   消息队列的长度（byte）
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回消息队列的 id ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_queue_create(char *qname,int qsize, unsigned int *err)
{
    if (err == NULL)
        return -1;

    for (int i=0; i<QUEUS_NUM; i++) {
        if(rts_msgq[i].Type == OS_OBJ_TYPE_NONE) {
            OSQCreate(&rts_msgq[i],qname,qsize,err);
            if (*err == OS_ERR_NONE)
                return i;
            else
                return -2;
        }
    }
    return -1;
}

/*
 *
 * 删除消息队列
 *
 * Description: 删除一个消息队列
 *
 * Arguments:
 *      [in]qnum    消息队列号
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_queue_del(int qnum,int opt, unsigned int *err)
{
    if (err == NULL)
        return -1;

    int ret=0 ;
    if(qnum <0 || qnum >= QUEUS_NUM || rts_msgq[qnum].Type != OS_OBJ_TYPE_Q) {
        return -1;
    }

    OSQDel(&rts_msgq[qnum],opt,err);

    if(*err != OS_ERR_NONE)
        return -2;
    else
        return ret;
}

/*
 *
 * 发送消息
 *
 * Description: 向消息队列发送消息
 *
 * Arguments:
 *      [in]qnum    消息队列号
 *      [in]buf     要发送的消息
 *      [in]size    消息长度
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_queue_post(int qnum,char *buf,int size,int opt, unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(qnum <0||qnum >=QUEUS_NUM ||rts_msgq[qnum].Type != OS_OBJ_TYPE_Q) {
        return -1;
    }

    OSQPost(&rts_msgq[qnum],buf,size,opt,err);
    if (*err != OS_ERR_NONE)
        return -2;
    else
        return 0;
}

/*
 *
 * 接收消息
 *
 * Description: 从消息队列接收消息
 *
 * Arguments:
 *      [in]qnum    消息队列号
 *      [out]buf    要发送的消息
 *      [out]ts     收到消息的时间戳
 *      [out]size   收到的消息长度
 *      [in]opt     选项
 *      [in]timeout 接收消息的超时时间(为0 则一直等待)
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_queue_get(int qnum,char *buf,unsigned short *size,int opt,int timeout, unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(qnum <0||qnum >=QUEUS_NUM ||rts_msgq[qnum].Type != OS_OBJ_TYPE_Q) {
        return -2;
    }

    buf=OSQPend(&rts_msgq[qnum],timeout,opt,size,NULL,err);

    if (*err == OS_ERR_PEND_WOULD_BLOCK) {
        return 1;
    } else if(*err != OS_ERR_NONE) {
        return -1;
    } else {
        return 0;
    }
}

/*
 *
 * 创建信号量
 *
 * Description: 创建一个指定大小的信号量
 *
 * Arguments:
 *      [in]sname   信号量名
 *      [in]cnt     信号量初始值
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回信号量id ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_sem_create(char *sname, unsigned int cnt,unsigned int *err)
{
    if (err == NULL)
        return -1;

    for (int i=0; i<SEM_NUM; i++) {
        if(rts_sem[i].Type == OS_OBJ_TYPE_NONE) {
            OSSemCreate(&rts_sem[i],sname,cnt,err);
            if (*err != OS_ERR_NONE)
                return -1;
            else
                return i;
        }
    }
    return -2;
}

/*
 *
 * 删除信号量
 *
 * Description: 删除一个信号量
 *
 * Arguments:
 *      [in]sid     信号量 id
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_sem_del(int sid,unsigned short opt,unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(sid>=SEM_NUM || sid <0 || rts_sem[sid].Type != OS_OBJ_TYPE_SEM)
        return -2;

    OSSemDel(&rts_sem[sid],opt,err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}

/*
 *
 * 等待信号
 *
 * Description: 等待信号量可用
 *
 * Arguments:
 *      [in]sid     信号量 id
 *      [in]timtout 等待超时时间
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回1/2 , non block 但未获取到信号量则返回 1
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
unsigned int os_sem_pend(int sid,unsigned int timeout,unsigned short opt,unsigned int *err)
{
    if (err == NULL)
        return 1;

    if(sid>=SEM_NUM || sid <0 || rts_sem[sid].Type != OS_OBJ_TYPE_SEM)
        return 2;
    OSSemPend(&rts_sem[sid],timeout,opt,NULL,err);

    if (*err == OS_ERR_PEND_WOULD_BLOCK) {
        return 1;
    } else if (*err != OS_ERR_NONE) {
        return 3;
    } else {
        return 0;
    }
}

/*
 *
 * 发送信号
 *
 * Description: 发送一个信号量
 *
 * Arguments:
 *      [in]sid     信号量 id
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
unsigned int os_sem_post(int sid, unsigned short opt, unsigned int *err)
{
    if (err == NULL)
        return 1;

    if(sid>=SEM_NUM || sid <0 || rts_sem[sid].Type != OS_OBJ_TYPE_SEM)
        return 2;
    OSSemPost(&rts_sem[sid],opt,err);
    if (*err != OS_ERR_NONE) {
        return 1;
    } else
        return 0;
}

/*
 *
 * 创建互斥量
 *
 * Description: 创建一个互斥量
 *
 * Arguments:
 *      [in]mname   互斥量名
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回互斥量 id ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_mutex_create(char *mname,unsigned int *err)
{
    if (err == NULL)
        return -1;

    for (int i=0; i<MUT_NUM; i++) {
        if(rts_mutex[i].Type == OS_OBJ_TYPE_NONE) {
            OSMutexCreate(&rts_mutex[i],mname,err);
            if (*err != OS_ERR_NONE)
                return -1;
            else
                return i;
        }
    }
    return -2;
}

/*
 *
 * 删除互斥量
 *
 * Description: 删除一个互斥量
 *
 * Arguments:
 *      [in]mid     互斥量id
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_mutex_del(int mid, unsigned short opt,unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(mid>=MUT_NUM || mid <0 || rts_mutex[mid].Type != OS_OBJ_TYPE_MUTEX)
        return -2;
    OSMutexDel(&rts_mutex[mid],opt,err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}

/*
 *
 * 申请互斥量
 *
 * Description: 申请互斥量
 *
 * Arguments:
 *      [in]mid     互斥量id
 *      [in]timeout 等待超时时间
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_mutex_pend(int mid,unsigned int timeout,unsigned short opt,unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(mid>=MUT_NUM || mid <0 || rts_mutex[mid].Type != OS_OBJ_TYPE_MUTEX)
        return -2;
    OSMutexPend(&rts_mutex[mid],timeout,opt,NULL,err);

    if (*err == OS_ERR_PEND_WOULD_BLOCK) {
        return 1;
    } else if (*err != OS_ERR_NONE) {
        return -1;
    } else {
        return 0;
    }
}

/*
 *
 * 释放互斥量
 *
 * Description: 释放互斥量
 *
 * Arguments:
 *      [in]mid     互斥量id
 *      [in]opt     选项
 *      [out]err    返回操作错误码
 *
 * Returns:
 *      成功则返回0 ， 失败返回-1/-2
 *
 * Note(s):
 *      出错时可以根据 err 的值查找失败原因
 *
 */
int os_mutex_post(int mid,unsigned short opt,unsigned int *err)
{
    if (err == NULL)
        return -1;

    if(mid>=MUT_NUM || mid <0 || rts_mutex[mid].Type != OS_OBJ_TYPE_MUTEX)
        return -2;
    OSMutexPost(&rts_mutex[mid],opt,err);
    if (*err != OS_ERR_NONE)
        return -1;
    else
        return 0;
}

/*
 * v1.1.3.
 * verison: x.y.z
 */   

char *os_version(void)
{
    return version_string;
}


#define OS_BLOCK_SIZE 0x01000000
void os_copy_data(UINT32 from, INT32 size)
{
    UINT32 *to = NULL;
    
    switch (os_get_mno()){
    case 0:
    case 1:
    case 2:
        to = from + 2 * OS_BLOCK_SIZE;
        break;
#if 0
    case 3:
        break;
    //case 0:
    case 4:
    case 5:
        to = from + OS_BLOCK_SIZE;
        break;
#endif
    default:
        break;
    }
    if(to != NULL){
        memcpy(to,from,size);
        //dma_memcpy(to,from,size);
    }
}

void os_copy_stack(void)
{
    UINT32 *from = NULL;
    UINT32 *to = NULL;
    UINT32 size = 0;

    switch (os_get_mno()){

    case 0:
    case 1:
    case 2:
        from = GAP_0;//KERNEL_STACK_LOW;
        to = GAP_0;//KERNEL_STACK_LOW + 2 * OS_BLOCK_SIZE,
//        size = TASK_SPESTACK_HIGH - KERNEL_STACK_LOW;
        size = /*IRQ_STACK_HIGH*/GAP_END - GAP_0;//KERNEL_STACK_LOW;
        break;
#if 0
    case 3:
        break;
    //case 0:
    case 4:
    case 5:
        from = KERNEL_STACK_LOW;
        to = KERNEL_STACK_LOW + OS_BLOCK_SIZE,
        //size = TASK_SPESTACK_HIGH - KERNEL_STACK_LOW;
        size = IRQ_STACK_HIGH- KERNEL_STACK_LOW;
        break;
#endif
    default:
        break;
    }
    if(from != NULL){
        memcpy(to,from,size);
        //dma_memcpy(to,from,size);
    }
}

void os_clear_stack(void)
{
    UINT32 *to=NULL;
    UINT32 size=0;

    switch (os_get_mno()){

    case 0:
    case 1:
    case 2:
        to = GAP_0/*KERNEL_STACK_LOW*/ + OS_BLOCK_SIZE;
        //size = TASK_SPESTACK_HIGH - KERNEL_STACK_LOW;
        size = /*IRQ_STACK_HIGH*/ GAP_END- GAP_0;//KERNEL_STACK_LOW;
        break;
#if 0
    case 3:
        break;
    //case 0:
    case 4:
    case 5:
        to = KERNEL_STACK_LOW + 2*OS_BLOCK_SIZE;
        //size = TASK_SPESTACK_HIGH - KERNEL_STACK_LOW;
        size = IRQ_STACK_HIGH- KERNEL_STACK_LOW;
        break;
#endif
    default:
        break;
    }


    if(to !=NULL){
        //   printf("ocs %x %x\n",to,size);
        memset(to,0,size);
    }
}
void os_clear_data(UINT32 from, INT32 size)
{
    UINT32 *to = NULL;

    switch (os_get_mno()){

    case 0:
    case 1:
    case 2:
        to = from + OS_BLOCK_SIZE;
        break;
#if 0
    case 3:
        break;
    //case 0:
    case 4:
    case 5:
        to = from + 2*OS_BLOCK_SIZE;
        break;
#endif
    default:
        break;
    }

    if(to != NULL){
        memset(to,0,size);
    }
}



void os_gap_fill()
{
    memset(GAP_0,0x00,GAP_SIZE);
    memset(GAP_1,0x00,GAP_SIZE);
    memset(GAP_2,0x00,GAP_SIZE);
    memset(GAP_3,0x00,GAP_SIZE);
    memset(GAP_4,0x00,GAP_SIZE);
    memset(GAP_5,0x00,GAP_SIZE);
    memset(GAP_6,0x00,GAP_SIZE);
    memset(GAP_7,0x00,GAP_SIZE);

#ifdef _CAG_CONFIG_AMP0
    for(int i=1;i<3;i++){
#else
    for(int i=1;i<4;i++){
#endif
        memset(TASK_STACK_HIGH- i *(GAP_SIZE+TASK_STACK_SIZE),0x00,GAP_SIZE);
    }
    for(int i=1;i<7;i++){
        memset(TASK_SPESTACK_HIGH- i *(GAP_SIZE+TASK_SPESTACK_SIZE),0x00,GAP_SIZE);
    }
}

void os_gap_check()
{
    int8_t broken=0;
    uint8_t buf[GAP_SIZE]={0x00};
    memset(buf,0x00,GAP_SIZE);
    int ret=0;
    printf("check\n");
    ret=memcmp(GAP_0,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_0+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_1,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_1+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_2,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        printf("%x\n",GAP_2);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_2+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_3,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        printf("%x\n",GAP_3);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_3+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_4,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_4+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_5,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_5+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_6,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_6+i));
        }
        broken=1;
        printf("\n");
    }
    ret=memcmp(GAP_7,buf,GAP_SIZE);
    if(ret !=0){
        powerpcIntDisable();
        printf("%s %d\n",__FUNCTION__,__LINE__);
        printf("%x\n",GAP_7);
        for(int i=0;i<GAP_SIZE;i++){
            printf("%x ",*(uint8_t *)(GAP_7+i));
        }
        broken=1;
        printf("\n");
    }

#ifdef _CAG_CONFIG_AMP0
    for(int i=1;i<3;i++){
#else
    for(int i=1;i<4;i++){
#endif
        ret=memcmp(TASK_STACK_HIGH- i *(GAP_SIZE+TASK_STACK_SIZE),buf,GAP_SIZE);
        if(ret !=0){
            powerpcIntDisable();
            printf("%s %d\n",__FUNCTION__,__LINE__);
            for(int j=0;j<GAP_SIZE;j++){
                printf("%x ",*(uint8_t *)(TASK_STACK_HIGH- i *(GAP_SIZE+TASK_STACK_SIZE)+j));
            }
            broken=1;
        printf("\n");
        }
    }
    for(int i=1;i<7;i++){
        ret=memcmp(TASK_SPESTACK_HIGH- i *(GAP_SIZE+TASK_SPESTACK_SIZE),buf,GAP_SIZE);
        if(ret !=0){
            powerpcIntDisable();
            printf("%s %d\n",__FUNCTION__,__LINE__);
            for(int j=0;j<GAP_SIZE;j++){
                printf("%x ",*(uint8_t *)(TASK_SPESTACK_HIGH- i *(GAP_SIZE+TASK_SPESTACK_SIZE)+j));
            }
            broken=1;
        printf("\n");
        }
    }
    if(broken==1){
        while(1);
    }
}
