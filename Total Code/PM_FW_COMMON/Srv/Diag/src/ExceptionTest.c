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
*  文件名称    : ExceptionTest.c
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-12-15
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
#include <Srv/Scheduler/include/string.h>
#include <Srv/Scheduler/cagos.h>
#include "Srv/Diag/inc/ExceptionTest.h"


/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                局部函数声明
***********************************************************************************************************************
*/
static void trap(void);

/*
***********************************************************************************************************************
*                                全局函数实现
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: ExceptionTestInit
*
* 功能描述: 异常自检初始化
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
void ExceptionTestInit(void)
{

    return;
}

/*
***********************************************************************************************************************
* 函数名称: ExceptionTestCycle
*
* 功能描述: 异常自检周期函数
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
uint32_t ExceptionTestCycle(puint32_t puiVectorTest)
{
    uint32_t uiFinished = TEST_FINISHED_FALSE;
    
    /* 对各种异常进行检查 */
    //trap();

    uiFinished = TEST_FINISHED_TRUE;
    
    return uiFinished;
}

/*
***********************************************************************************************************************
*                                局部函数实现
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: trap
*
* 功能描述: 对各种异常进行检查
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
static void trap(void)
{
    unsigned long *addr = 0xFFFFFFFF;
    unsigned long content = 0;
    VOIDFUNCPTR vFunc = 0;

    //inst miss exception
    vFunc = 0xdeadbeaf;
    (*vFunc) ();

    //the data miss exception
    *(unsigned long *) 0xdeadbeaf = 0x0;

    //program exception
    vFunc = 0xf000ffff;
    (*vFunc) ();

    //the data storage exception
    content = *(unsigned long *) addr;

    //the aligned exception
    content = 0x100003;
    sysAli(content); // oslib库函数

    return;
}


/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

