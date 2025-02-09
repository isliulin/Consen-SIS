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
*  文件名称    : SysTest.h
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-11-18
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/
#ifndef _SYSTEST_H
#define _SYSTEST_H

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
#define INT_EN             (0x00000001U)                       /* interrupt Enable */
#define INT_DIS            (0x00000000U)                       /* interrupt Disable */
#define DCACHE_EN          (0x00000001U)                       /* Dcache Enable */
#define DCACHE_DIS         (0x00000000U)                       /* Dcache Disable */
#define ICACHE_EN          (0x00000001U)                       /* Icache Enable */
#define ICACHE_DIS         (0x00000000U)                       /* Icache Disable */
#define CMP_EQUAL          (0x00000000U)                       /* compare equal 0 */
#define CMP_GREAT          (0x00000001U)                       /* compare great 1 */
#define CMP_LESS           (0xFFFFFFFFU)                       /* compare less -1 */



#define CFG_DATA_SIZE                 (0x1000000U)

/* first compile: */
/* data base address */
#define CFG_FIR_DATABASE            (0x02000000U)

/* second compile: */
/* data base address */
#define CFG_SEC_DATABASE            (0x03000000U)

/* third compile: */
/* data base address */
#define CFG_THI_DATABASE            (0x06000000U)

/* fourth compile: */
/* data base address */
#define CFG_FOUR_DATABASE            (0x07000000U)


/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
/* 控制器执行空间 */
typedef enum
{
    EXECUTE_A = 0x00000000U,                               /* 执行空间: A id = 0 */
    EXECUTE_B,                                             /* 执行空间: B id = 1 */
    EXECUTE_C,                                             /* 执行空间: C id = 2 */
    MAX_PROGRAMS                                           /* max programs */
}excute_id;


/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SysGetCurExeIndex
*
* 功能描述: 获取当前代码运行索引号。
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 运行索引号
*
* 注意事项: 无
***********************************************************************************************************************
*/
excute_id SysGetCurExeIndex(void);

/*
***********************************************************************************************************************
* 函数名称: SysSetCurExeIndex
*
* 功能描述: 设置当前代码运行索引号。
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 运行索引号
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSetCurExeIndex(excute_id emRunIndex);

#endif/* #ifndef _SYSTEST_H */
