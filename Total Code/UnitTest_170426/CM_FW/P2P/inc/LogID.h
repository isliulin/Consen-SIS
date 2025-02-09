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
*  文件名称    : LogID.h
*
*  功能简介    :
*
*  作者            : 王东
*
*  创建日期    : 2017-02-14
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef P2PLOGID_H_
#define P2PLOGID_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

/*
*  前10位基址在该文件定义，后22位在其它.h文件中定义 (注意： 按照图中的格式对后22位进行使用)
* ______________________________________________________________________________
* |      log ID 格式规划                                                                                                                          |
* |_____________________________________________________________________________|
* |  主模块号（8bit）                |错误等级 （2bit）|文件号（6bit） |错误号 （16bit）              |
* |-----------------------------------------------------------------------------|
* | AMS:      0x00         | 0-致命   1-严重    |             |                     |
* | Client:   0x01         | 2-一般   3-提示    |             |                     |
* | CommonLib:0x02         |               |             |                     |
* | Config:   0x03         |               |             |                     |
* | CS1131:   0x04         |               |             |                     |
* | Diag:     0x05         |               |             |                     |
* | ExterComm:0x06         |               |             |                     |
* | GPS:      0x07         |               |             |                     |
* | InterComm:0x08         |               |             |                     |
* | LED:      0x09         |               |             |                     |
* | Log:      0x0A         |               |             |                     |
* | Modbus:   0x0B         |               |             |                     |
* | Monitor:  0x0C         |               |             |                     |
* | NTP:      0x0D         |               |             |                     |
* | OPC:      0x0E         |               |             |                     |
* | P2P:      0x0F         |               |             |                     |
* | SOE:      0x10         |               |             |                     |
* | Sys:      0x11         |               |             |                     |
* | Task:     0x12         |               |             |                     |
* | Version:  0x13         |               |             |                     |
* |___________________|_____________|___________|______________________________|
*/

/* ------------  L0: 致命  ----------------------------------------------------*/
/*#define LOG_ID_P2P_LEVEL0                    (0x0F000000U)*/
#define LOGID_P2P_E_CMBUS                      (0x0F000000U)
#define LOGID_P2P_E_PM_TIMEOUT                 (0x0F000001U)
#define LOGID_P2P_E_SEND_PM_REQ                (0x0F000002U)
#define LOGID_P2P_E_SEND_PM_RESP               (0x0F000003U)

#define LOGID_P2P_E_SYS_SET_EXT_REQ            (0x0F000020U)  /* SysSetP2PMsg: P2P_EXT_REQ */
#define LOGID_P2P_E_SYS_SET_EXT_RESP           (0x0F000021U)  /* SysSetP2PMsg: P2P_EXT_RESP */

#define LOGID_P2P_E_MSG_EXT_RESP               (0x0F000040U)  /* P2P_EXT_RESP */
#define LOGID_P2P_E_MSG_EXT_REQ                (0x0F000041U)  /* P2P_EXT_REQ */
#define LOGID_P2P_E_MSG_PM_RESP                (0x0F000042U)  /* P2P_PM_RESP */
#define LOGID_P2P_E_MSG_PM_REQ                 (0x0F000043U)  /* P2P_PM_REQ */

/* ------------  L1: 严重  ----------------------------------------------------*/
/*#define LOG_ID_P2P_LEVEL1                    (0x0F400000U)*/



/* ------------  L2: 一般  ----------------------------------------------------*/
/*#define LOG_ID_P2P_LEVEL2                    (0x0F800000U)*/


/* ------------  L3: 提示  ----------------------------------------------------*/
/*#define LOG_ID_P2P_LEVEL3                    (0x0FC00000U)*/

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

#endif /* P2PLOGID_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

