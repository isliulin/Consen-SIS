/*
 *------------------------------------------------------------
 * Project:	cagOS
 * Goal:  platform dec code for p1020rdb.
 * Copyright (c) 2013, 2014 CAG Systems, Inc.
 *------------------------------------------------------------
 *
 *    @@@@     @@@      @@@@@       ####      ######
 *  @@       @@  @@    @@         ##    ##   ##
 * @@       @@    @@  @@   @@@@  ##      ## ######
 * @@      @@@@@@@@@@ @@    @@    ##    ##      ##
 *  @@@@@ @@@      @@@  @@@@@@      ####  #######
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable CAG license agreement.
 *
 * 1 tab == 4 spaces!
 *------------------------------------------------------------
 * modification history
 * --------------------
 * 03jun15,Jeff created
 *
 * DESCRIPTION
 * This file contains the board DEC component
 */
#include <config.h>
#include <libc/stdio.h>
#include <kernel/sysOsTimer.h>

UINT32 sysClockFreq = 0;
UINT32 sysclkFrequency = 0;
UINT32 rolloverPeriod = 0;
UINT32 ticksPerSecond = 0; /* The number of ticks per second of the system clock */
IMPORT UINT32 sysClkFreqGet(void);
IMPORT void clockTaskStart (void *p_arg);
IMPORT void OS_TaskReturn (void);
IMPORT void OSTimeTick (void);
IMPORT void sysEpicConfig(void);

void  clockTaskStart (void *p_arg)
{
    printf("1%s %d\n",__FUNCTION__,__LINE__);
    os_gap_check();
    sysClockFreq = sysClkFreqGet ();
    sysclkFrequency = sysClockFreq >> 3;
    rolloverPeriod = M85XX_MAX_COUNT_VALUE / sysclkFrequency;
    ticksPerSecond = DEFAULT_DEC_TICKS_PER_SECOND;
    UINT32 msr = 0;

    (void)&p_arg;
    __asm__ __volatile__ ("mfmsr %0":"=r" (msr):);
    msr &= ~(_PPC_MSR_EE);
    msr |= _PPC_MSR_EE;
    __asm__ __volatile__ ("mtmsr %0"::"r" (msr));

#if _CAG_CONFIG_EPIC == 0
    
    UINT32 maxTimerCount = (sysclkFrequency + 1000) / 1000;
    
    /* clear the pending DEC interrupt */

    sysTsrSet (TSR_DIS);

    /* load the DEC counter and DECAR with the count */

    sysDecarSet (maxTimerCount);
    sysDecSet (maxTimerCount);

    /* Enable the DEC interrupt */

    sysTcrSet (sysTcrGet() | TCR_DIE | TCR_ARE);

    /* Enable the TBEN in HID0 */

    sysHid0Set (sysHid0Get() | _PPC_HID0_TBEN);

#else
    sysEpicConfig();
#endif

#if 0
    print_init(0);//ȥ�������Ĵ�ӡ��Ϣ
#endif

    printf("clock init done\n");
    os_gap_check();
    OS_TaskReturn();
    while(1) {
        printf("timer_init\n");
    }
}

void OSDecHandler(void)
{
    sysDecIntAck ();
    OSTimeTick();
}
