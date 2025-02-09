﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 系统资源管理模块
*
*  文件名称    : SysModbus.h
*
*  功能简介    :
*
*  作者       : 李琦
*
*  创建日期    : 2015-12-31
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SYS_MODBUS_H_
#define SYS_MODBUS_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "DataType.h"
#include "Hardware.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#define MAX_MODBUS_MSG_LEN         350         /*最大请求或应答消息内容长度  */
#define MAX_MODBUS_MSG_NUM         100         /*每个队列中的最大条数  */

#define MAX_MODBUS_TCP_MSG_LEN     500         /*最大请求或应答消息内容长度  */
#define MAX_MODBUS_TCP_MASTER_NUM  16          /* ModbusTCP主站个数  */
#define MAX_MODBUS_TCP_MSG_NUM     10          /* ModbusTCP主站一次发送消息的条数  */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
/* 消息*/
typedef struct SysModbusMsgTag
{
    uint16_t usLen;                             /* 消息内容长度 */
    uint8_t ucContent[MAX_MODBUS_MSG_LEN];      /* 存放消息内容 */
} SysModbusMsg_t;

/* 消息队列*/
typedef struct SysModbusMsgQueueTag
{
    uint16_t usHead;                            /* 队列头部*/
    uint16_t usTail;                            /* 队列尾部 */
    uint16_t usNum;                             /* 队列中元素个数 */
    SysModbusMsg_t stMsg[MAX_MODBUS_MSG_NUM];   /* 消息 */
} SysModbusMsgQueue_t;

/* 消息*/
typedef struct SysModbusTCPMsgTag
{
    uint16_t usLen;                             /* 消息内容长度 */
    uint8_t ucContent[MAX_MODBUS_TCP_MSG_LEN];  /* 存放消息内容 */
} SysModbusTCPMsg_t;

/* 消息队列*/
typedef struct SysModbusTCPMsgQueueTag
{
    uint16_t usHead;                            /* 队列头部*/
    uint16_t usTail;                            /* 队列尾部 */
    uint16_t usNum;                             /* 队列中元素个数 */
    SysModbusTCPMsg_t stMsg[MAX_MODBUS_TCP_MSG_NUM];   /* 消息 */
} SysModbusTCPMsgQueue_t;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: SysModbusInit
*
* 功能描述: 队列初始化
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
void SysModbusInit(void);

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusMsgQueue
*
* 功能描述: 从系统资源模块获取消息（请求/应答）
*
* 输入参数: emPMID: PM的ID
*
* 输出参数: pucContent: 指向待读出的消息内容
*         pusLen: 指向待读出的消息内容长度
*
* 返 回 值  : true-收到消息
*        false- 1)无数据  2)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusMsgQueue (PMController_t emPMID, puint8_t pucContent, puint16_t pusLen);

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusMsgNum
*
* 功能描述: 从系统资源模块获取消息（请求/应答）的个数
*
* 输入参数: emPMID: PM的ID
*
* 输出参数: pusNum: 指向待读出的消息内容长度
*
* 返 回 值  : true-读取成功
*        false- 1)无数据   2)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusMsgNum (PMController_t emPMID, puint16_t pusNum);

/*
***********************************************************************************************************************
* 函数名称: SysSetModbusMsgQueue
*
* 功能描述: 将消息写入系统资源模块
*
* 输入参数: emPMID: PM的ID
*        pucContent: 指向待写入的消息内容
*        usLen: 指向待写入的消息内容长度
*
* 输出参数: 无
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetModbusMsgQueue(PMController_t emPMID, puint8_t pucContent, uint16_t usLen);

/*
***********************************************************************************************************************
* 函数名称: SysSetModbusTCPMasterMsg
*
* 功能描述: 将ModbusTCP消息写入系统资源模块
*
* 输入参数: ucMasterIndex: 主站索引号
*        pucContent: 指向待写入的消息内容
*        usLen: 指写入的消息内容长度
*
* 输出参数: 无
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetModbusTCPMasterMsg(uint8_t ucMasterIndex, puint8_t pucContent, uint16_t usLen);

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusTCPMasterMsg
*
* 功能描述: 从系统资源模块读取ModbusTCP消息
*
* 输入参数: ucMasterIndex: 主站索引号
*
* 输出参数: pucContent: 指向待写入的消息内容
*        pusLen: 指向待写入的消息内容长度
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusTCPMasterMsg(uint8_t ucMasterIndex, puint8_t pucContent, puint16_t pusLen);

/*
***********************************************************************************************************************
* 函数名称: SysClearModbusTCPMasterMsg
*
* 功能描述: 清除系统资源模块ModbusTCP消息
*
* 输入参数: ucMasterIndex: 主站索引号
*
* 输出参数:
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysClearModbusTCPMasterMsg( uint8_t ucMasterIndex );

#endif /* SYS_MODBUS_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

