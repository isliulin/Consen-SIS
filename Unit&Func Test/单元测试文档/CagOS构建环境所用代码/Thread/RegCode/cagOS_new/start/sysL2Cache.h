/* sysL2Cache.h -  L2 cache defines */

/*
 *------------------------------------------------------------
 * Project:	cagOS
 * Goal:  L2Cache header file for PPC85XX.
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
 * This file contains the L2Cache library
 */

/* L2 Cache defines */

/* L2CTL */

#define M85XX_L2CTL(x)         (CAST(VUINT32 *)((x + 0x20000)))

#define NO_L2_EXT_WRITE_REGIONS     4
#define M85XX_L2CEWARn(x,n)    (CAST(VUINT32 *)((x + 0x20010) + (n * 0x10)))
#define M85XX_L2CEWCRn(x,n)    (CAST(VUINT32 *)((x + 0x20018) + (n * 0x10)))

#define M85XX_L2SRBAR0(x)      (CAST(VUINT32 *)((x + 0x20100)))
#define M85XX_L2SRBAR1(x)      (CAST(VUINT32 *)((x + 0x20108)))
#define M85XX_L2ERRINJHI(x)    (CAST(VUINT32 *)((x + 0x20E00)))
#define M85XX_L2ERRINJLO(x)    (CAST(VUINT32 *)((x + 0x20E04)))
#define M85XX_L2ERRINJCTL(x)   (CAST(VUINT32 *)((x + 0x20E08)))
#define M85XX_L2ERRCAPTDATAHI(x)   (CAST(VUINT32 *)((x + 0x20E20)))
#define M85XX_L2ERRCAPTDATALO(x)   (CAST(VUINT32 *)((x + 0x20E24)))
#define M85XX_L2ERRCAPTECC(x)  (CAST(VUINT32 *)((x + 0x20E28)))
#define M85XX_L2ERRDET(x)      (CAST(VUINT32 *)((x + 0x20E40)))
#define M85XX_L2ERRDIS(x)      (CAST(VUINT32 *)((x + 0x20E44)))
#define M85XX_L2ERRINTEN(x)    (CAST(VUINT32 *)((x + 0x20E48)))
#define M85XX_L2ERRATTR(x)     (CAST(VUINT32 *)((x + 0x20E4C)))
#define M85XX_L2ERRADDR(x)     (CAST(VUINT32 *)((x + 0x20E50)))
#define M85XX_L2ERRCTL(x)      (CAST(VUINT32 *)((x + 0x20E58)))

/* L2CTL BIT MASKS and BIT SHIFTS */
#define M85XX_L2CTL_L2E_MSK      0x80000000
#define M85XX_L2CTL_L2E_BIT      31
#define M85XX_L2CTL_L2I_MSK      0x40000000
#define M85XX_L2CTL_L2I_BIT      30
#define M85XX_L2CTL_L2SIZ_MSK    0x30000000 /* Read Only */
#define M85XX_L2CTL_L2SIZ_BIT    28

/* Size vs bit value */
#define L2SIZ_1024KB             3
#define L2SIZ_512KB              2
#define L2SIZ_256KB              1
#define L2SIZ_0KB                0

#define M85XX_L2CTL_L2DO_MSK     0x00400000
#define M85XX_L2CTL_L2DO_BIT     22
#define M85XX_L2CTL_L2IO_MSK     0x00200000
#define M85XX_L2CTL_L2IO_BIT     21
#define M85XX_L2CTL_L2MEXTDIS_MSK 0x00100000
#define M85XX_L2CTL_L2MEXTDIS_BIT 20
#define M85XX_L2CTL_L2INTDIS_MSK  0x00080000
#define M85XX_L2CTL_L2INTDIS_BIT  19
#define M85XX_L2CTL_L2SRAM_MSK    0x00070000
#define M85XX_L2CTL_L2SRAM_BIT    16
#define M85XX_L2CTL_L2LO_MSK      0x00002000
#define M85XX_L2CTL_L2LO_BIT      13
#define M85XX_L2CTL_L2SLC_MSK     0x00001000
#define M85XX_L2CTL_L2SLC_BIT     12
#define M85XX_L2CTL_L2LFR_MSK     0x00000400
#define M85XX_L2CTL_L2LFR_BIT     10
#define M85XX_L2CTL_L2LFRID_MSK   0x00000300
#define M85XX_L2CTL_L2LFRID_BIT   8

/* L2CWAR BIT MASK */
#define M85XX_L2CEWAR_ADDR_MSK          0xFFFFFF00

/* L2CEWCR BIT MASK and BIT SHIFT*/
#define M85XX_L2CEWCR_E_MSK            0x80000000
#define M85XX_L2CEWCR_E_BIT            31
#define M85XX_L2CEWCR_LOCK_MSK         0x40000000
#define M85XX_L2CEWCR_LOCK_BIT         30
#define M85XX_L2CEWCR_SIZMASK_MSK      0x00FFFFFF
#define M85XX_L2CEWCR_SIZMASK_BIT      0

/* L2SRBAR MASK and SHIFT */
#define M85XX_L2SRBAR_ADDR_MSK         0xFFFFC000
#define M85XX_L2SRBAR_ADDR_BIT         14

