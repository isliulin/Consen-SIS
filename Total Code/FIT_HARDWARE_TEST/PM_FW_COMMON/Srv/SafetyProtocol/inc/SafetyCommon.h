﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*                                  
*                                  
*  项目名称    : 安全控制系统
*
*  模块名称    : 安全通讯公共部分
*
*  文件名称    : SafetyCommon.h
*
*  功能简介    : 安全通讯公共部分处理
*
*  作者        : 王东
*
*  创建日期    : 2016-04-18
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SAFETY_COMM_H_
#define SAFETY_COMM_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include <Srv/Scheduler/include/stdio.h>
#include "inc/DataType.h"
#include "inc/Hardware.h"
#include "Srv/Sys/inc/CommSys.h"
#include "Srv/SharedMem/inc/SharedSafetyComm.h"
#include "Srv/SharedMem/inc/SharedConfig.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define DEBUG_SAFETYCOMM

#define MAX_TOL_CNTS   (3)        /* 容忍次数上限值 */
#define MAX_ERR_CNTS   (64)       /* 错误计数上限值 */
#define INIT_RECV_SEQ  (0xFFFFU)  /* 站间通讯接收序号初始值 */

#define BIT_0          (0x0001U)  /* Bit0 */
#define BIT_1          (0x0002U)  /* Bit1 */
#define BIT_2          (0x0004U)  /* Bit2 */
#define BIT_3          (0x0008U)  /* Bit3 */

#define BIT_4          (0x0010U)  /* Bit4 */
#define BIT_5          (0x0020U)  /* Bit5 */
#define BIT_6          (0x0040U)  /* Bit6 */
#define BIT_7          (0x0080U)  /* Bit7 */

#define BIT_8          (0x0100U)  /* Bit8 */
#define BIT_9          (0x0200U)  /* Bit9 */
#define BIT_10         (0x0400U)  /* Bit10 */
#define BIT_11         (0x0800U)  /* Bit11 */

#define BIT_12         (0x1000U)  /* Bit12 */
#define BIT_13         (0x2000U)  /* Bit13 */
#define BIT_14         (0x4000U)  /* Bit14 */
#define BIT_15         (0x8000U)  /* Bit15 */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* Communication Error Info.  通信错误信息结构体定义 */
typedef struct CommErrorInfoTag
{
    uint16_t usErrCnt;      /* Error count     错误计数 */
    bool_t bTolFlag;        /* Tolerance Flag  容忍标志位 */
    bool_t bErrFlag;        /* Error Flag      错误标志位 */
}CommErrorInfo_t;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: UpdateTolInfo
*
* 功能描述: 更新容忍次数和重新计算容忍门限值
*
* 输入参数: pucTolCnt：待更新的容忍次数；
*          pucTolThr：待更新的容忍门限值。
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void UpdateTolInfo( uint8_t *pucTolCnt, uint8_t *pucTolThr );

/*
***********************************************************************************************************************
* 函数名称: HandleSafetyCommError
*
* 功能描述: 安全通讯错误处理函数
*
* 输入参数: pstErrInfo：错误信息；
*          ucTolThr：容忍门限值。
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void HandleSafetyCommError( CommErrorInfo_t *pstErrInfo, uint8_t ucTolThr );

/*
***********************************************************************************************************************
* 函数名称: HandleSafetyCommRecover
*
* 功能描述: 安全通讯恢复处理函数
*
* 输入参数: pstErrInfo：错误信息
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void HandleSafetyCommRecover( CommErrorInfo_t *pstErrInfo );

/*
***********************************************************************************************************************
* 函数名称: CompareData
*
* 功能描述: 比较数据是否相同
*
* 输入参数: pucData1：数据1首地址；
*          pucData2：数据2首地址；
*          uiDataLen：数据长度。
*
* 输出参数: 无
*
* 返 回 值: 是否相同
*
* 注意事项: 无
***********************************************************************************************************************
*/

bool_t CompareData( uint8_t const pucData1[], uint8_t const pucData2[], uint32_t uiDataLen );

/*
***********************************************************************************************************************
* 函数名称: ReverseData
*
* 功能描述: 翻转数据：按位翻转
*
* 输入参数: pucSrcData：原始数据首地址；
*          uiDataLen：数据长度；
*          pucDstData：目标数据首地址。
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void ReverseData( uint8_t pucSrcData[], uint32_t uiDataLen, uint8_t pucDstData[]);

#endif /* SAFETY_COMM_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/


