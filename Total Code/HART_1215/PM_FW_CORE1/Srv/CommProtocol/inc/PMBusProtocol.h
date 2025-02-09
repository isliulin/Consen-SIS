﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 通讯协议模块
*
*  文件名称    : PMBusProtocol.h
*
*  功能简介    : 负责PM与PM间的数据通讯
*
*  作者       : 李琦
*
*  创建日期    : 2016-03-18
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef PM_BUS_PROTOCOL_H_
#define PM_BUS_PROTOCOL_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "inc/Hardware.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
/* 发送标识*/
#define CPU_CON_PRE                 (0U)  /* 发给前一个                   */
#define CPU_CON_NEXT                (1U)  /* 发给后一个                   */
#define CPU_CON_PRE_AND_NEXT        (2U)  /* 发给前一个和后一个           */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* 通讯类型 */
typedef enum
{
    SEND = 0x00000000U,                                    /* 通讯类型:本机发送数据 = 0 */
    RECV,                                                  /* 通讯类型:本机接收数据 = 1 */
    MAX_COMTYPE                                            /* max comtype */
}com_type_t;

/* 数据类型 */
typedef enum
{
    INPUT_DATA = 0x00000000U,                              /* 数据类型:IO模块输入数据 id = 0 */
    OUTPUT_DATA,                                           /* 数据类型:IO模块输出数据 id = 1 */
    SYNC_DATA                                              /* 数据类型:静态数据 id = 2 */
}data_type_t;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: PMBusProtocolInit
*
* 功能描述: 初始化函数
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
void PMBusProtocolInit (void);

/*
***********************************************************************************************************************
* 函数名称: PMBusProtocolCycle
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
void PMBusProtocolCycle (void);


/*
***********************************************************************************************************************
* 函数名称: PMBusProtocolCycle
*
* 功能描述: 判断是否有用户数据。
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
uint32_t PMProtocolHasData(PMController_t emSrcPMId, PMController_t emLocalPMId);

/*
***********************************************************************************************************************
* 函数名称: PMBusProtocolCycle
*
* 功能描述: 接收用户数据，并判断数据正确性。
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
uint32_t PMProtocolRecvData(uint8_t ucRecv[], PMController_t emLocalPMId, PMController_t emSrcPMId, \
                            data_type_t emRecvType);

#endif /* PM_BUS_PROTOCOL_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

