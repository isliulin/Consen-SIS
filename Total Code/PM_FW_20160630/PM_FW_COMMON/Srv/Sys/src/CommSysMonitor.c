/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    :
*
*  文件名称    : CommSysMonitor.c
*
*  功能简介    : 完成Core1内状态的监控，处理同步模块同步的部分任务（需要Core1处理的）
*
*  作者            : 刘阳
*
*  创建日期    : 2016-04-14
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
#include "../inc/CommSysMonitor.h"


/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static uint8_t s_ucIECShedCtrlFlg[MAX_TASK_NUM];
static uint8_t s_ucInputPollFlg[MAX_TASK_NUM];
static uint8_t s_ucOutputPollFlg[MAX_TASK_NUM];
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
* 函数名称: SysGetIECShedCtrlFlg
*
* 功能描述: 获取指定任务的任务调度控制标志
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
uint8_t SysGetIECShedCtrlFlg(Task_ID_t emTaskID)
{
    return s_ucIECShedCtrlFlg[emTaskID];
}
/*
***********************************************************************************************************************
* 函数名称: SysSetIECShedCtrlFlg
*
* 功能描述: 获取指定任务的任务调度控制标志
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
void SysSetIECShedCtrlFlg(Task_ID_t emTaskID, uint8_t ucIECShedCtrlFlg)
{
    if(emTaskID < MAX_TASK_NUM)
    {
        s_ucIECShedCtrlFlg[emTaskID] = ucIECShedCtrlFlg;
    }
    return;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetInputPollCtrlFlg
*
* 功能描述: 获取指定任务的输入轮询控制标志
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
uint8_t SysGetInputPollFlg(Task_ID_t emTaskID)
{
    return s_ucInputPollFlg[emTaskID];
}
/*
***********************************************************************************************************************
* 函数名称: SysSetInputPollFlg
*
* 功能描述: 获取指定任务的输入轮询控制标志
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
void SysSetInputPollFlg(Task_ID_t emTaskID, uint8_t ucInputPollCtrlFlg)
{
    s_ucInputPollFlg[emTaskID] = ucInputPollCtrlFlg;
    return;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetOutputPollFlg
*
* 功能描述: 获取指定任务的输出轮询控制标志
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
uint8_t SysGetOutputPollFlg(Task_ID_t emTaskID)
{
    return s_ucOutputPollFlg[emTaskID];
}
/*
***********************************************************************************************************************
* 函数名称: SysSetOutputPollFlg
*
* 功能描述: 获取指定任务的输出轮询控制标志
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
void SysSetOutputPollFlg(Task_ID_t emTaskID, uint8_t ucOutputPollCtrlFlg)
{
    s_ucOutputPollFlg[emTaskID] = ucOutputPollCtrlFlg;
    return;
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
