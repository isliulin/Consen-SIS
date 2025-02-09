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
*  文件名称    : Monitor.h
*
*  功能简介    :
*
*  作者            : 刘阳
*
*  创建日期    : 2016-04-28
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef MONITOR_H_
#define MONITOR_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "../../../Srv/SysResource/inc/SysMonitor.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

//#define DEBUG_OUT_MINITOR
#ifdef DEBUG_OUT_MINITOR
#define DEBUG_MONITOR(format, args...)  printf ("MONITOR:  ") ; printf(format, ##args)
#else
#define DEBUG_MONITOR(format, args...)
#endif


#define NEED_INIT                       (0x01)
#define NOT_NEED_INIT                   (0x02)

#define CFG_MINIMUM_BEAT_TIME           (500U)




/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

typedef void (*GlobaInit)(uint32_t);


#pragma pack (1)

typedef struct MSGHeadTag
{
    uint8_t ucType;                      /*0xAA*/
    uint8_t ucProtect;                  /*0xBB*/
    uint16_t usActualType;              /*Actually message type*/
    uint8_t ucNodeNum;                  /*control station node number*/
    uint8_t ucPMNum;
    uint16_t usSequenceNum;             /*request message sequence number*/
    uint8_t ucLastFlag;                 /*last package flag*/
    uint8_t ucReserved[5];
    uint16_t usLength;                  /*message data length (head + Data Area)*/

}MSGHead_t;



#pragma pack ()
/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: MonitorInit
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
void MonitorInit(void);

/*
***********************************************************************************************************************
* 函数名称: MonitorCycle
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
void MonitorCycle(void);

#endif /* MONITOR_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

