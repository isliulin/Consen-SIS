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
*  文件名称    : Version.c
*
*  功能简介    : 显示版本号
*
*  作者       : 李琦
*
*  创建日期    : 2016-07-14
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
#include <stdio.h>
#include "../inc/Version.h"
#include "Sys/inc/CMLocalbus.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static uint8_t s_ucVersion[]={"CM version: 2017/04/24"};
static uint8_t s_uiCMRTSVer[4] = {1,0,0,18};
static uint8_t s_uiCMOSVer[4] = {1,0,0,2};

/*
***********************************************************************************************************************
*                                局部函数声明
***********************************************************************************************************************
*/
static void ShowfpgaVer(void);

/*
***********************************************************************************************************************
*                                全局函数实现
***********************************************************************************************************************
*/




/*
***********************************************************************************************************************
* 函数名称: ShowCMVersion
*
* 功能描述: 显示版本号
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void ShowCMVersion(void)
{
    printf("%s\n", &s_ucVersion[0]);
    SysSetCM2PMVer(&s_uiCMRTSVer[0], &s_uiCMOSVer[0]);
    SysSetCM2PMState();
    ShowfpgaVer();
    return ;
}

/*
***********************************************************************************************************************
*                                局部函数实现
***********************************************************************************************************************
*/
static void ShowfpgaVer(void)
{
    uint16_t usVal = 0;
    
    usVal = SysGetFPGAModID();
    printf("FPGA MOD ID: 0x%x\n", usVal);
    usVal = SysGetFPGAHardwareVer();
    printf("FPGA HARDWARE VERSION: 0x%x\n", usVal);
    usVal = SysGetFPGAChipID();
    printf("FPGA MICROCHIP ID: 0x%x\n", usVal);
    usVal = SysGetFPGAFirmwareVer();
    printf("FPGA FIRMWARE VERSION: 0x%x\n", usVal);
    usVal = SysGetMCUModID();
    printf("MCU MOD ID: 0x%x\n", usVal);
    usVal = SysGetMCUHardwareVer();
    printf("MCU HARDWARE VERSION: 0x%x\n", usVal);
    usVal = SysGetMCUChipID();
    printf("MCU MICROCHIP ID: 0x%x\n", usVal);
    usVal = SysGetMCUFirmwareVer();
    printf("MCU FIRMWARE VERSION: 0x%x\n", usVal);
    return;
}
/*
***********************************************************************************************************************
文件结束
***********************************************************************************************************************
*/
