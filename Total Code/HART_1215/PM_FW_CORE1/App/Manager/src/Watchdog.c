﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
* 
*  模块名称    : 
*
*  文件名称    : Watchdog.c
*
*  功能简介    : 
*
*  作者          : 李琦
*
*  创建日期    : 2016-08-05
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
#include <Srv/Scheduler/include/stdio.h>
#include "../inc/Watchdog.h"
#include "Srv/Sys/inc/CommSys.h"
#include "Srv/Scheduler/cagos.h"
#include "Srv/SharedMem/inc/SharedMem.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static uint32_t s_uiCount = 0;
static uint32_t s_uiRTSCount = 0;

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
* 函数名称: WatchdogManagerInit
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
void WatchdogManagerInit(void)
{
    SysWatchdogConfig(WTD_CONFIG_ENABLE);
    SysSetWatchdogLowLimit(WTD_LOW_LIMIT);
    SysSetWatchdogHighLimit(WTD_HIGH_LIMIT);

    /* GPIO5管脚初始化 */
    sysGpioLineConfig (GPIO_5, GPIO_OUT);
    sysGpioLineSet (GPIO_5, GPIO_HIGH);

    s_uiCount = 0;
    s_uiRTSCount = 0;
}

/*
***********************************************************************************************************************
* 函数名称: WatchdogManagerEnable
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
void WatchdogManagerEnable(void)
{
    SysWatchdogEnable();
}

/*
***********************************************************************************************************************
* 函数名称: WatchdogManagerCycle
*
* 功能描述: 周期运行函数
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
void WatchdogManagerCycle(void)
{
    static uint32_t uiCore0CounterOld = 0;
    uint32_t uiCore0CounterNew = 0;
    bool_t bRet = false;

    do
    {

        bRet = SysGetSMWatchdogInfo(&uiCore0CounterNew);
    }while(bRet != true);

    //printf("cnt0=%d cnt1=%d\n", uiCore0CounterNew, s_uiCount);

    if((0 == uiCore0CounterNew) || (uiCore0CounterNew != uiCore0CounterOld))
    {
        /* 操作GPIO5每次翻转，喂狗 */
        if(0 == s_uiCount % 2)
        {
            sysGpioLineSet (GPIO_5, GPIO_HIGH);
            //printf("g1\n");
        }
        else
        {
            sysGpioLineSet (GPIO_5, GPIO_LOW);
            //printf("g0\n");
        }
    }
    else
    {
        printf("c0 wtd err %d\n",uiCore0CounterNew);
    }
    uiCore0CounterOld = uiCore0CounterNew;

    return;
}

/*
***********************************************************************************************************************
* 函数名称: UpdateWatchdogCounter
*
* 功能描述: 更新看门狗计数器
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
void UpdateWatchdogCounter(void)
{
    s_uiCount++;
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
