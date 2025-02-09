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
*  文件名称    : SharedPRG.h
*
*  功能简介    : 用户工程在共享内存上运行，core1负责加载用户程序，core0负责执行用户程序
*
*  作者            : 李琦
*
*  创建日期    : 2016-06-14
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SHARED_PRG_H_
#define SHARED_PRG_H_

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

/* 用户程序区长度 */
#define MAX_PRG_AREA_LEN           (100*1024u)   /* 程序区大小 */


#define PRG_AREA_LOCKED              (true)        /* 程序区被锁定，不允许访问*/
#define PRG_AREA_UNLOCKED            (false)       /* 程序未锁定，允许访问 */

#define PRG_AREA_READ_ONLY           (true)        /* 实时数据区只读标识 */
#define PRG_AREA_WRITE_ONLY          (false)       /* 实时数据区只写标识 */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* -------------------用户程序数据结构------------------------------------------------------------------------------------ */
/* 实时数据区 */
typedef struct SharedPRGAreaTag
{
    bool_t bLock;                                  /* 是否可以被访问:true-不允许访问 false-允许访问 */
    bool_t bStatus;                                /* 两种状态：只读或只写: true-只读 false-只写*/
    uint8_t ucPRG[MAX_PRG_AREA_LEN];               /* 存放用户程序 */
}SharedPRGArea_t;



/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SharedPRGInit
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
void SharedPRGInit(void);


/*
***********************************************************************************************************************
*                                全局变量
***********************************************************************************************************************
*/
extern SharedPRGArea_t g_stSharedPRG;


#endif /* SHARED_RTDATA_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

