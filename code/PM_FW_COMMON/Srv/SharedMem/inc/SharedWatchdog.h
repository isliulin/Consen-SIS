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
*  文件名称    : SharedWatchdog.h
*
*  功能简介    : core0与core1间看门狗相关的共享变量
*
*  作者            : 李琦
*
*  创建日期    : 2016-08-08
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SHARED_WTD_H_
#define SHARED_WTD_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "inc/Hardware.h"
#include "Srv/Sys/inc/CommSysCommon.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/


/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* 信箱 */
typedef struct SMWatchdogTag
{
    uint32_t uiLock;                                /* 是否可以被访问 */
    uint32_t uiCounter;                             /* 任务运行计数器*/
} SMWatchdog_t;


/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SharedWatchdogInit
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
void SharedWatchdogInit(void);

/*
***********************************************************************************************************************
* 函数名称: SysGetSMWatchdogInfo
*
* 功能描述: 从共享内存中获取看门狗相关的信息
*
* 输入参数: 无
*
* 输出参数: puiCounter: 计数值
*
* 返 回 值  : true-收到消息
*        false- 1)不允许访问  2)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetSMWatchdogInfo(puint32_t puiCounter);

/*
***********************************************************************************************************************
* 函数名称: SysSetSMWatchdogInfo
*
* 功能描述: 向共享内存中设置看门狗相关的信息
*
* 输入参数: uiCounter：计数值
*
* 输出参数: 无
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetSMWatchdogInfo(uint32_t uiCounter);

#endif /* SHARED_WTD_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

