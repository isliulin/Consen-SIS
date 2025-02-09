﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
* 
*  模块名称    : 共享内存
*
*  文件名称    : SharedMem.c
*
*  功能简介    : core0与core1间的共享内存
*
*  作者            : 李琦
*
*  创建日期    : 2016-04-15
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include <Srv/Scheduler/include/string.h>
#include <Srv/Scheduler/include/stdio.h>
#include <Srv/Scheduler/cagos.h>
#include "../inc/SharedMem.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static Pause_Flag_t s_emSysPauseFlag[MAX_TASK_NUM];

/*
***********************************************************************************************************************
*                                局部函数声明
***********************************************************************************************************************
*/


/*
***********************************************************************************************************************
*                                全局函数实现
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: SharedMemInit
*
* 功能描述: 初始化
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SharedMemInit(void)
{
    /* 0为core0,1为core1 */
    if(0==get_cpu_no())
    {
        /* 初始化 */
        SharedCommInit();
        SharedConfigInit();
        SharedRtDataInit();
        SharedSOEInit();
        LEDInit();
        SharedWatchdogInit();
        SharedFlagInit();
        SharedHandshakeInit();
        SharedSafetyCommInit();

    }

    return;
}

/*
***********************************************************************************************************************
* 函数名称: SharedFlagInit
*
* 功能描述: 共享内存上标志位的初始化。
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SharedFlagInit(void)
{
    s_emSysPauseFlag[TASK_UP1] = PF_CONTINUE;
    s_emSysPauseFlag[TASK_UP2] = PF_CONTINUE;
    
    return;
}

/*
***********************************************************************************************************************
* 函数名称: SharedSetPauseFlag
*
* 功能描述: 设置系统的暂停标志。
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SharedSetPauseFlag(Pause_Flag_t emSysPauseFlag,Task_ID_t emTaskID)
{
    if(((PF_CONTINUE == emSysPauseFlag ) || (PF_PAUSE == emSysPauseFlag )) && (emTaskID < MAX_TASK_NUM))
    {
        atomic32Set(&s_emSysPauseFlag[emTaskID], emSysPauseFlag);
    }

    return;
}
/*
***********************************************************************************************************************
* 函数名称: SharedGetPauseFlag
*
* 功能描述: 获取系统的暂停标志。
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
Pause_Flag_t SharedGetPauseFlag(Task_ID_t emTaskID)
{
    Pause_Flag_t emPauseFlag = PF_CONTINUE;
    
    if(emTaskID < MAX_TASK_NUM)
    {
        emPauseFlag = atomic32Get(&s_emSysPauseFlag[emTaskID]);
    }
    return emPauseFlag;
}

/*
***********************************************************************************************************************
*                                局部函数实现
***********************************************************************************************************************
*/


/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
