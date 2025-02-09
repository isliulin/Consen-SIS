/*
 * Copyright 2010-2011 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/*
 * QorIQ RDB boards configuration file
 */
#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_LIB_RAND

#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_DISPLAY_BOARDINFO

#ifdef CONFIG_36BIT
#define CONFIG_PHYS_64BIT
#endif

#if defined(CONFIG_P1020MBG)
#define CONFIG_BOARDNAME "P1020MBG-PC"
#define CONFIG_P1020
#define CONFIG_VSC7385_ENET
#define CONFIG_SLIC
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0xe4
#define __SW_BOOT_SD		0x54
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P1020UTM)
#define CONFIG_BOARDNAME "P1020UTM-PC"
#define CONFIG_P1020
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0xe0
#define __SW_BOOT_SD		0x50
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P1020RDB_PC)
#define CONFIG_BOARDNAME "P1020RDB-PC"
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_P1020
#define CONFIG_SPI_FLASH
#define CONFIG_VSC7385_ENET
#define CONFIG_SLIC
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0x5c
#define __SW_BOOT_SPI		0x1c
#define __SW_BOOT_SD		0x9c
#define __SW_BOOT_NAND		0xec
#define __SW_BOOT_PCIE		0x6c
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

/*
 * P1020RDB-PD board has user selectable switches for evaluating different
 * frequency and boot options for the P1020 device. The table that
 * follow describe the available options. The front six binary number was in
 * accordance with SW3[1:6].
 * 111101 533 533 267 667 NOR Core0 boot; Core1 hold-off
 * 101101 667 667 333 667 NOR Core0 boot; Core1 hold-off
 * 011001 800 800 400 667 NOR Core0 boot; Core1 hold-off
 * 001001 800 800 400 667 SD/MMC Core0 boot; Core1 hold-off
 * 001101 800 800 400 667 SPI Core0 boot; Core1 hold-off
 * 010001 800 800 400 667 NAND Core0 boot; Core1 hold-off
 * 011101 800 800 400 667 PCIe-2 Core0 boot; Core1 hold-off
 */
#if defined(CONFIG_P1020RDB_PD)
#define CONFIG_BOARDNAME "P1020RDB-PD"
#define CONFIG_P1020
#define CONFIG_SPI_FLASH
#if defined(FSL_CONFIG_SOC)
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_SPI_FLASH
#define CONFIG_VSC7385_ENET
#endif

#define CONFIG_SLIC
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0x64
#define __SW_BOOT_SPI		0x34
#define __SW_BOOT_SD		0x24
#define __SW_BOOT_NAND		0x44
#define __SW_BOOT_PCIE		0x74
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P1021RDB)
#define CONFIG_BOARDNAME "P1021RDB-PC"
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_P1021
#define CONFIG_QE
#define CONFIG_SPI_FLASH
#define CONFIG_VSC7385_ENET
#define CONFIG_SYS_LBC_LBCR	0x00080000	/* Implement conversion of
						addresses in the LBC */
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0x5c
#define __SW_BOOT_SPI		0x1c
#define __SW_BOOT_SD		0x9c
#define __SW_BOOT_NAND		0xec
#define __SW_BOOT_PCIE		0x6c
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P1024RDB)
#define CONFIG_BOARDNAME "P1024RDB"
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_P1024
#define CONFIG_SLIC
#define CONFIG_SPI_FLASH
#define __SW_BOOT_MASK		0xf3
#define __SW_BOOT_NOR		0x00
#define __SW_BOOT_SPI		0x08
#define __SW_BOOT_SD		0x04
#define __SW_BOOT_NAND		0x0c
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P1025RDB)
#define CONFIG_BOARDNAME "P1025RDB"
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_P1025
#define CONFIG_QE
#define CONFIG_SLIC
#define CONFIG_SPI_FLASH

#define CONFIG_SYS_LBC_LBCR	0x00080000	/* Implement conversion of
						addresses in the LBC */
#define __SW_BOOT_MASK		0xf3
#define __SW_BOOT_NOR		0x00
#define __SW_BOOT_SPI		0x08
#define __SW_BOOT_SD		0x04
#define __SW_BOOT_NAND		0x0c
#define CONFIG_SYS_L2_SIZE	(256 << 10)
#endif

#if defined(CONFIG_P2020RDB)
#define CONFIG_BOARDNAME "P2020RDB-PCA"
#define CONFIG_NAND_FSL_ELBC
#define CONFIG_P2020
#define CONFIG_SPI_FLASH
#define CONFIG_VSC7385_ENET
#define __SW_BOOT_MASK		0x03
#define __SW_BOOT_NOR		0xc8
#define __SW_BOOT_SPI		0x28
#define __SW_BOOT_SD		0x68 /* or 0x18 */
#define __SW_BOOT_NAND		0xe8
#define __SW_BOOT_PCIE		0xa8
#define CONFIG_SYS_L2_SIZE	(512 << 10)
#endif

#ifdef CONFIG_SDCARD
#error "SDC"
#define CONFIG_SPL
#define CONFIG_SPL_MPC8XXX_INIT_DDR_SUPPORT
#define CONFIG_SPL_ENV_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_MMC_SUPPORT
#define CONFIG_SPL_MMC_MINIMAL
#define CONFIG_SPL_FLUSH_IMAGE
#define CONFIG_SPL_TARGET		"u-boot-with-spl.bin"
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_I2C_SUPPORT
#define CONFIG_FSL_LAW                 /* Use common FSL init code */
#define CONFIG_SYS_TEXT_BASE		0x11001000
#define CONFIG_SPL_TEXT_BASE		0xf8f81000
#define CONFIG_SPL_PAD_TO		0x20000
#define CONFIG_SPL_MAX_SIZE		(128 * 1024)
#define CONFIG_SYS_MMC_U_BOOT_SIZE	(768 << 10)
#define CONFIG_SYS_MMC_U_BOOT_DST	(0x11000000)
#define CONFIG_SYS_MMC_U_BOOT_START	(0x11000000)
#define CONFIG_SYS_MMC_U_BOOT_OFFS	(128 << 10)
#define CONFIG_SYS_MPC85XX_NO_RESETVEC
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot.lds"
#define CONFIG_SPL_MMC_BOOT
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_COMMON_INIT_DDR
#endif
#endif

#ifdef CONFIG_SPIFLASH
#error "SPI"
#define CONFIG_SPL
#define CONFIG_SPL_MPC8XXX_INIT_DDR_SUPPORT
#define CONFIG_SPL_ENV_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_SPI_SUPPORT
#define CONFIG_SPL_SPI_FLASH_SUPPORT
#define CONFIG_SPL_SPI_FLASH_MINIMAL
#define CONFIG_SPL_FLUSH_IMAGE
#define CONFIG_SPL_TARGET		"u-boot-with-spl.bin"
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_I2C_SUPPORT
#define CONFIG_FSL_LAW         /* Use common FSL init code */
#define CONFIG_SYS_TEXT_BASE		0x11001000
#define CONFIG_SPL_TEXT_BASE		0xf8f81000
#define CONFIG_SPL_PAD_TO		0x20000
#define CONFIG_SPL_MAX_SIZE		(128 * 1024)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_SIZE	(768 << 10)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_DST		(0x11000000)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_START	(0x11000000)
#define CONFIG_SYS_SPI_FLASH_U_BOOT_OFFS	(128 << 10)
#define CONFIG_SYS_MPC85XX_NO_RESETVEC
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot.lds"
#define CONFIG_SPL_SPI_BOOT
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_COMMON_INIT_DDR
#endif
#endif

#ifdef CONFIG_NAND
#error "NAND"
#define CONFIG_SPL
#define CONFIG_TPL
#ifdef CONFIG_TPL_BUILD
#define CONFIG_SPL_NAND_BOOT
#define CONFIG_SPL_FLUSH_IMAGE
#define CONFIG_SPL_ENV_SUPPORT
#define CONFIG_SPL_NAND_INIT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_I2C_SUPPORT
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_MPC8XXX_INIT_DDR_SUPPORT
#define CONFIG_SPL_COMMON_INIT_DDR
#define CONFIG_SPL_MAX_SIZE		(128 << 10)
#define CONFIG_SPL_TEXT_BASE		0xf8f81000
#define CONFIG_SYS_MPC85XX_NO_RESETVEC
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(832 << 10)
#define CONFIG_SYS_NAND_U_BOOT_DST	(0x11000000)
#define CONFIG_SYS_NAND_U_BOOT_START	(0x11000000)
#define CONFIG_SYS_NAND_U_BOOT_OFFS	((128 + 128) << 10)
#elif defined(CONFIG_SPL_BUILD)
#define CONFIG_SPL_INIT_MINIMAL
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_FLUSH_IMAGE
#define CONFIG_SPL_TARGET		"u-boot-with-spl.bin"
#define CONFIG_SPL_TEXT_BASE		0xff800000
#define CONFIG_SPL_MAX_SIZE		4096
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(128 << 10)
#define CONFIG_SYS_NAND_U_BOOT_DST	0xf8f80000
#define CONFIG_SYS_NAND_U_BOOT_START	0xf8f80000
#define CONFIG_SYS_NAND_U_BOOT_OFFS	(128 << 10)
#endif /* not CONFIG_TPL_BUILD */

#define CONFIG_SPL_PAD_TO		0x20000
#define CONFIG_TPL_PAD_TO		0x20000
#define CONFIG_SPL_TARGET		"u-boot-with-spl.bin"
#define CONFIG_SYS_TEXT_BASE		0x11001000
#define CONFIG_SYS_LDSCRIPT	"arch/powerpc/cpu/mpc85xx/u-boot-nand.lds"
#endif

#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE		0xeff40000
#endif

#ifndef CONFIG_RESET_VECTOR_ADDRESS
#define CONFIG_RESET_VECTOR_ADDRESS	0xeffffffc
#endif

#ifndef CONFIG_SYS_MONITOR_BASE
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SPL_TEXT_BASE
#else
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_TEXT_BASE	/* start of monitor */
#endif
#endif

/* High Level Configuration Options */
#define CONFIG_BOOKE
#define CONFIG_E500

#define CONFIG_MP

#define CONFIG_FSL_ELBC
#define CONFIG_PCI

#if !defined(CM_CONFIG_SOC)
#define CONFIG_PCIE1	/* PCIE controler 1 (slot 1) */
#define CONFIG_PCIE2	/* PCIE controler 2 (slot 2) */
#else
#define CONFIG_PCIE1	/* PCIE controler 1 (slot 1) */
#endif

#define CONFIG_FSL_PCI_INIT	/* Use common FSL init code */
#define CONFIG_PCI_INDIRECT_BRIDGE	/* indirect PCI bridge support */
#define CONFIG_FSL_PCIE_RESET	/* need PCIe reset errata */
#define CONFIG_SYS_PCI_64BIT	/* enable 64-bit PCI resources */

#define CONFIG_FSL_LAW
/*#define CONFIG_TSEC_ENET*/	/* tsec ethernet support */
#define CONFIG_ENV_OVERWRITE

#if !defined(FSL_CONFIG_SOC)
/*#define CONFIG_PHY_MARVELL*//*1111111*/
#endif

#define CONFIG_CMD_SATA
#define CONFIG_SATA_SIL
#define CONFIG_SYS_SATA_MAX_DEVICE	2
#define CONFIG_LIBATA
#define CONFIG_LBA48

#if defined(CONFIG_P2020RDB)
#define CONFIG_SYS_CLK_FREQ	100000000
#else
#define CONFIG_SYS_CLK_FREQ	66666666
#endif
#define CONFIG_DDR_CLK_FREQ	66666666

#define CONFIG_HWCONFIG
/*
 * These can be toggled for performance analysis, otherwise use default.
 */
/*#define CONFIG_L2_CACHE*//*test*/
#define CONFIG_BTB

#define CONFIG_BOARD_EARLY_INIT_F	/* Call board_pre_init */

#define CONFIG_ENABLE_36BIT_PHYS

#ifdef CONFIG_PHYS_64BIT
#define CONFIG_ADDR_MAP			1
#define CONFIG_SYS_NUM_ADDR_MAP		16	/* number of TLB1 entries */
#endif

#define CONFIG_SYS_MEMTEST_START	0x00200000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x1fffffff
#define CONFIG_PANIC_HANG	/* do not reset board on panic */

#define CONFIG_SYS_CCSRBAR		0xffe00000
#define CONFIG_SYS_CCSRBAR_PHYS_LOW	CONFIG_SYS_CCSRBAR

/* IN case of NAND bootloader relocate CCSRBAR in RAMboot code not in the 4k
       SPL code*/
#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_CCSR_DO_NOT_RELOCATE
#endif

/* DDR Setup */
#define CONFIG_SYS_FSL_DDR3
#if defined(FSL_CONFIG_SOC)
#define CONFIG_SYS_DDR_RAW_TIMING
#define CONFIG_DDR_SPD
#define CONFIG_SYS_SPD_BUS_NUM 1
#define SPD_EEPROM_ADDRESS 0x52
#endif


#undef CONFIG_FSL_DDR_INTERACTIVE

#if (defined(CONFIG_P1020MBG) || defined(CONFIG_P1020RDB_PD))
#if !defined(FSL_CONFIG_SOC)
#define CONFIG_SYS_SDRAM_SIZE_LAW	LAW_SIZE_512M
#define CONFIG_CHIP_SELECTS_PER_CTRL	1
#else
#define CONFIG_SYS_SDRAM_SIZE_LAW	LAW_SIZE_2G
#define CONFIG_CHIP_SELECTS_PER_CTRL	2
#endif

#else
#define CONFIG_SYS_SDRAM_SIZE_LAW	LAW_SIZE_1G
#define CONFIG_CHIP_SELECTS_PER_CTRL	1
#endif
#define CONFIG_SYS_SDRAM_SIZE		(1u << (CONFIG_SYS_SDRAM_SIZE_LAW - 19))
#define CONFIG_SYS_DDR_SDRAM_BASE	0x00000000
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_SDRAM_BASE

#define CONFIG_NUM_DDR_CONTROLLERS	1
#if !defined(FSL_CONFIG_SOC)
#define CONFIG_DIMM_SLOTS_PER_CTLR	2 /*ezio modify 4.1*/
#else
#define CONFIG_DIMM_SLOTS_PER_CTLR	1
#endif

/* Default settings for DDR3 */
#ifndef CONFIG_P2020RDB
#define CONFIG_SYS_DDR_CS0_CONFIG	0x80014302
#define CONFIG_SYS_DDR_CS0_CONFIG_2	0x00000000
#ifdef FSL_CONFIG_SOC
#define CONFIG_SYS_DDR_CS0_BNDS		0x0000003f
#define CONFIG_SYS_DDR_CS1_BNDS		0x0040007f
#define CONFIG_SYS_DDR_CS1_CONFIG	0x80014302
#define CONFIG_SYS_DDR_CS1_CONFIG_2	0x00000000
#else
#define CONFIG_SYS_DDR_CS0_BNDS		0x0000001f /*cag board only use one bnd*/
#endif


#define CONFIG_SYS_DDR_DATA_INIT	0xdeadbeef
#define CONFIG_SYS_DDR_INIT_ADDR	0x00000000
#define CONFIG_SYS_DDR_INIT_EXT_ADDR	0x00000000
#define CONFIG_SYS_DDR_MODE_CONTROL	0x00000000

#define CONFIG_SYS_DDR_ZQ_CONTROL	0x89080600
#define CONFIG_SYS_DDR_WRLVL_CONTROL	0x8655A608
#define CONFIG_SYS_DDR_SR_CNTR		0x00000000
#define CONFIG_SYS_DDR_RCW_1		0x00000000
#define CONFIG_SYS_DDR_RCW_2		0x00000000
#define CONFIG_SYS_DDR_CONTROL		0xE70C0000	/* Type = DDR3	*/ /*enable ecc*/
#define CONFIG_SYS_DDR_CONTROL_2	0x04401050
#define CONFIG_SYS_DDR_TIMING_4		0x00220001
#define CONFIG_SYS_DDR_TIMING_5		0x03402400

#define CONFIG_SYS_DDR_TIMING_3		0x00020000
#define CONFIG_SYS_DDR_TIMING_0		0x00330004
#define CONFIG_SYS_DDR_TIMING_1		0x6f6B4846
#define CONFIG_SYS_DDR_TIMING_2		0x0FA8C8CF
#define CONFIG_SYS_DDR_CLK_CTRL		0x03000000
#define CONFIG_SYS_DDR_MODE_1		0x40461520
#define CONFIG_SYS_DDR_MODE_2		0x8000c000
#define CONFIG_SYS_DDR_INTERVAL		0x0C300000
#endif

#undef CONFIG_CLOCKS_IN_MHZ

/*
 * Memory map
 *
 * 0x0000_0000 0x7fff_ffff	DDR		Up to 2GB cacheable
 * 0x8000_0000 0xdfff_ffff	PCI Express Mem	1.5G non-cacheable(PCIe * 3)
 * 0xec00_0000 0xefff_ffff	NOR flash	Up to 64M non-cacheable	CS0/1
 * 0xf8f8_0000 0xf8ff_ffff	L2 SRAM		Up to 512K cacheable
 *   (early boot only)
 * 0xff80_0000 0xff80_7fff	NAND flash	32K non-cacheable	CS1/0
 * 0xff98_0000 0xff98_ffff	PMC		64K non-cacheable	CS2
 * 0xffa0_0000 0xffaf_ffff	CPLD		1M non-cacheable	CS3
 * 0xffb0_0000 0xffbf_ffff	VSC7385 switch  1M non-cacheable	CS2
 * 0xffc0_0000 0xffc3_ffff	PCI IO range	256k non-cacheable
 * 0xffd0_0000 0xffd0_3fff	L1 for stack	16K cacheable
 * 0xffe0_0000 0xffef_ffff	CCSR		1M non-cacheable
 */


/*
 * Local Bus Definitions
 */
#if (defined(CONFIG_P1020MBG) || defined(CONFIG_P1020RDB_PD))
#define CONFIG_SYS_MAX_FLASH_SECT	512	/* 64M */
#define CONFIG_SYS_FLASH_BASE		0xec000000
#elif defined(CONFIG_P1020UTM)
#define CONFIG_SYS_MAX_FLASH_SECT	256	/* 32M */
#define CONFIG_SYS_FLASH_BASE		0xee000000
#else
#define CONFIG_SYS_MAX_FLASH_SECT	128	/* 16M */
#define CONFIG_SYS_FLASH_BASE		0xef000000
#endif


#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_FLASH_BASE_PHYS	(0xf00000000ull | CONFIG_SYS_FLASH_BASE)
#else
#define CONFIG_SYS_FLASH_BASE_PHYS	CONFIG_SYS_FLASH_BASE
#endif

#define CONFIG_FLASH_BR_PRELIM (BR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS) \
	| BR_PS_16 | BR_V)

#define CONFIG_FLASH_OR_PRELIM	0xfc000ff7

#define CONFIG_SYS_FLASH_BANKS_LIST	{CONFIG_SYS_FLASH_BASE_PHYS}
#define CONFIG_SYS_FLASH_QUIET_TEST
#define CONFIG_FLASH_SHOW_PROGRESS	45	/* count down from 45/5: 9..1 */

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* number of banks */

#undef CONFIG_SYS_FLASH_CHECKSUM
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000	/* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500	/* Flash Write Timeout (ms) */

#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_EMPTY_INFO
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE

/* Nand Flash */
#ifdef CONFIG_NAND_FSL_ELBC
#define CONFIG_SYS_NAND_BASE		0xff800000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_NAND_BASE_PHYS	0xfff800000ull
#else
#define CONFIG_SYS_NAND_BASE_PHYS	CONFIG_SYS_NAND_BASE
#endif

#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_MTD_NAND_VERIFY_WRITE
#define CONFIG_CMD_NAND
#if defined(CONFIG_P1020RDB_PD)
#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)
#else
#define CONFIG_SYS_NAND_BLOCK_SIZE	(16 * 1024)
#endif

#define CONFIG_SYS_NAND_BR_PRELIM (BR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
	| (2<<BR_DECC_SHIFT)	/* Use HW ECC */ \
	| BR_PS_8	/* Port Size = 8 bit */ \
	| BR_MS_FCM	/* MSEL = FCM */ \
	| BR_V)	/* valid */
#if defined(CONFIG_P1020RDB_PD)
#define CONFIG_SYS_NAND_OR_PRELIM	(OR_AM_32KB \
	| OR_FCM_PGS	/* Large Page*/ \
	| OR_FCM_CSCT \
	| OR_FCM_CST \
	| OR_FCM_CHT \
	| OR_FCM_SCY_1 \
	| OR_FCM_TRLX \
	| OR_FCM_EHTR)
#else
#define CONFIG_SYS_NAND_OR_PRELIM	(OR_AM_32KB	/* small page */ \
	| OR_FCM_CSCT \
	| OR_FCM_CST \
	| OR_FCM_CHT \
	| OR_FCM_SCY_1 \
	| OR_FCM_TRLX \
	| OR_FCM_EHTR)
#endif
#endif /* CONFIG_NAND_FSL_ELBC */

#define CONFIG_BOARD_EARLY_INIT_R	/* call board_early_init_r function */

#define CONFIG_SYS_INIT_RAM_LOCK
#define CONFIG_SYS_INIT_RAM_ADDR	0xffd00000 /* stack in RAM */
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_HIGH 0xf
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_LOW CONFIG_SYS_INIT_RAM_ADDR
/* The assembler doesn't like typecast */
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS \
	((CONFIG_SYS_INIT_RAM_ADDR_PHYS_HIGH * 1ull << 32) | \
	  CONFIG_SYS_INIT_RAM_ADDR_PHYS_LOW)
#else
/* Initial L1 address */
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS	CONFIG_SYS_INIT_RAM_ADDR
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_HIGH 0
#define CONFIG_SYS_INIT_RAM_ADDR_PHYS_LOW CONFIG_SYS_INIT_RAM_ADDR_PHYS
#endif
/* Size of used area in RAM */
#define CONFIG_SYS_INIT_RAM_SIZE	0x00004000

#define CONFIG_SYS_GBL_DATA_OFFSET	(CONFIG_SYS_INIT_RAM_SIZE - \
					GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_OFFSET	CONFIG_SYS_GBL_DATA_OFFSET

#define CONFIG_SYS_MONITOR_LEN	(768 * 1024)
#define CONFIG_SYS_MALLOC_LEN	(1024 * 1024)/* Reserved for malloc */

#define CONFIG_SYS_CPLD_BASE	0xffa00000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_CPLD_BASE_PHYS	0xfffa00000ull
#else
#define CONFIG_SYS_CPLD_BASE_PHYS	CONFIG_SYS_CPLD_BASE
#endif
/* CPLD config size: 1Mb */
#define CONFIG_CPLD_BR_PRELIM	(BR_PHYS_ADDR(CONFIG_SYS_CPLD_BASE_PHYS) | \
					BR_PS_8 | BR_V)
#define CONFIG_CPLD_OR_PRELIM	(0xfff009f7)

#define CONFIG_SYS_PMC_BASE	0xff980000
#define CONFIG_SYS_PMC_BASE_PHYS	CONFIG_SYS_PMC_BASE
#define CONFIG_PMC_BR_PRELIM	(BR_PHYS_ADDR(CONFIG_SYS_PMC_BASE_PHYS) | \
					BR_PS_8 | BR_V)
#define CONFIG_PMC_OR_PRELIM	(OR_AM_64KB | OR_GPCM_CSNT | OR_GPCM_XACS | \
				 OR_GPCM_SCY | OR_GPCM_TRLX | OR_GPCM_EHTR | \
				 OR_GPCM_EAD)

#if !defined(FSL_CONFIG_SOC)
#define CAG_SYS_SRAM_BASE1 0xff600000
#define CAG_SYS_FPGA_BASE1 0xff700000
#endif

#ifdef CONFIG_NAND
#define CONFIG_SYS_BR0_PRELIM	CONFIG_SYS_NAND_BR_PRELIM /* NAND Base Addr */
#define CONFIG_SYS_OR0_PRELIM	CONFIG_SYS_NAND_OR_PRELIM /* NAND Options */
#define CONFIG_SYS_BR1_PRELIM	CONFIG_FLASH_BR_PRELIM	/* NOR Base Address */
#define CONFIG_SYS_OR1_PRELIM	CONFIG_FLASH_OR_PRELIM	/* NOR Options */
#else
#define CONFIG_SYS_BR0_PRELIM	CONFIG_FLASH_BR_PRELIM	/* NOR Base Address */
#define CONFIG_SYS_OR0_PRELIM	CONFIG_FLASH_OR_PRELIM	/* NOR Options */
#ifdef CONFIG_NAND_FSL_ELBC
#define CONFIG_SYS_BR1_PRELIM	CONFIG_SYS_NAND_BR_PRELIM /* NAND Base Addr */
#define CONFIG_SYS_OR1_PRELIM	CONFIG_SYS_NAND_OR_PRELIM /* NAND Options */
#endif

/*fpga*/
#if !defined(FSL_CONFIG_SOC)
#define CONFIG_SYS_BR2_PRELIM   (BR_PHYS_ADDR(CAG_SYS_FPGA_BASE1) \
                | BR_PS_16 \
                | BR_V)
#define CONFIG_SYS_OR2_PRELIM   0xFFF00FF6 //spd 3.25  //0xfff00c40 //copy from 651 ffc-fff

/*sram*/
#define CONFIG_SYS_BR1_PRELIM   (BR_PHYS_ADDR(CAG_SYS_SRAM_BASE1) \
                | BR_PS_16 \
                | BR_V)
#define CONFIG_SYS_OR1_PRELIM   0xfff00c40  //copy from 651 ffc-fff
#endif

#define CAG_GPIO_BASE  (CONFIG_SYS_CCSRBAR + CONFIG_SYS_MPC85xx_GPIO_OFFSET)
#define CONFIG_FSL_DMA
#endif

#if defined(FSL_CONFIG_SOC)
#define CONFIG_SYS_BR3_PRELIM	CONFIG_CPLD_BR_PRELIM	/* CPLD Base Address */
#define CONFIG_SYS_OR3_PRELIM	CONFIG_CPLD_OR_PRELIM	/* CPLD Options */
#endif

/* Vsc7385 switch */
#ifdef CONFIG_VSC7385_ENET
#define CONFIG_SYS_VSC7385_BASE		0xffb00000

#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_VSC7385_BASE_PHYS	0xfffb00000ull
#else
#define CONFIG_SYS_VSC7385_BASE_PHYS	CONFIG_SYS_VSC7385_BASE
#endif

#define CONFIG_SYS_VSC7385_BR_PRELIM	\
	(BR_PHYS_ADDR(CONFIG_SYS_VSC7385_BASE_PHYS) | BR_PS_8 | BR_V)
#define CONFIG_SYS_VSC7385_OR_PRELIM	(OR_AM_128KB | OR_GPCM_CSNT | \
			OR_GPCM_XACS |  OR_GPCM_SCY_15 | OR_GPCM_SETA | \
			OR_GPCM_TRLX |  OR_GPCM_EHTR | OR_GPCM_EAD)

#define CONFIG_SYS_BR2_PRELIM	CONFIG_SYS_VSC7385_BR_PRELIM
#define CONFIG_SYS_OR2_PRELIM	CONFIG_SYS_VSC7385_OR_PRELIM

/* The size of the VSC7385 firmware image */
#define CONFIG_VSC7385_IMAGE_SIZE	8192
#endif

/*
 * Config the L2 Cache as L2 SRAM
*/
#if defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_SDCARD) || defined(CONFIG_SPIFLASH)
#define CONFIG_SYS_INIT_L2_ADDR		0xf8f80000
#define CONFIG_SYS_INIT_L2_ADDR_PHYS	CONFIG_SYS_INIT_L2_ADDR
#define CONFIG_SYS_INIT_L2_END	(CONFIG_SYS_INIT_L2_ADDR + CONFIG_SYS_L2_SIZE)
#define CONFIG_SPL_RELOC_TEXT_BASE	0xf8f81000
#define CONFIG_SPL_GD_ADDR		(CONFIG_SYS_INIT_L2_ADDR + 112 * 1024)
#define CONFIG_SPL_RELOC_STACK		(CONFIG_SYS_INIT_L2_ADDR + 116 * 1024)
#define CONFIG_SPL_RELOC_STACK_SIZE	(32 << 10)
#define CONFIG_SPL_RELOC_MALLOC_ADDR	(CONFIG_SYS_INIT_L2_ADDR + 148 * 1024)
#if defined(CONFIG_P2020RDB)
#define CONFIG_SPL_RELOC_MALLOC_SIZE	(364 << 10)
#else
#define CONFIG_SPL_RELOC_MALLOC_SIZE	(108 << 10)
#endif
#elif defined(CONFIG_NAND)
#ifdef CONFIG_TPL_BUILD
#define CONFIG_SYS_INIT_L2_ADDR		0xf8f80000
#define CONFIG_SYS_INIT_L2_ADDR_PHYS	CONFIG_SYS_INIT_L2_ADDR
#define CONFIG_SYS_INIT_L2_END	(CONFIG_SYS_INIT_L2_ADDR + CONFIG_SYS_L2_SIZE)
#define CONFIG_SPL_RELOC_TEXT_BASE	0xf8f81000
#define CONFIG_SPL_RELOC_STACK		(CONFIG_SYS_INIT_L2_ADDR + 192 * 1024)
#define CONFIG_SPL_RELOC_MALLOC_ADDR	(CONFIG_SYS_INIT_L2_ADDR + 208 * 1024)
#define CONFIG_SPL_RELOC_MALLOC_SIZE	(48 << 10)
#define CONFIG_SPL_GD_ADDR		(CONFIG_SYS_INIT_L2_ADDR + 176 * 1024)
#else
#define CONFIG_SYS_INIT_L2_ADDR		0xf8f80000
#define CONFIG_SYS_INIT_L2_ADDR_PHYS	CONFIG_SYS_INIT_L2_ADDR
#define CONFIG_SYS_INIT_L2_END	(CONFIG_SYS_INIT_L2_ADDR + CONFIG_SYS_L2_SIZE)
#define CONFIG_SPL_RELOC_TEXT_BASE	(CONFIG_SYS_INIT_L2_END - 0x2000)
#define CONFIG_SPL_RELOC_STACK		((CONFIG_SYS_INIT_L2_END - 1) & ~0xF)
#endif /* CONFIG_TPL_BUILD */
#endif
#endif

/* Serial Port - controlled on board with jumper J8
 * open - index 2
 * shorted - index 1
 */
#define CONFIG_CONS_INDEX		1
#undef CONFIG_SERIAL_SOFTWARE_FIFO
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_SYS_NS16550_CLK		get_bus_freq(0)
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_INIT_MINIMAL)
#define CONFIG_NS16550_MIN_FUNCTIONS
#endif

#define CONFIG_SYS_BAUDRATE_TABLE	\
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200}

#define CONFIG_SYS_NS16550_COM1	(CONFIG_SYS_CCSRBAR+0x4500)
#define CONFIG_SYS_NS16550_COM2	(CONFIG_SYS_CCSRBAR+0x4600)

/* Use the HUSH parser */
#define CONFIG_SYS_HUSH_PARSER

/*
 * Pass open firmware flat tree
 */
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_OF_STDOUT_VIA_ALIAS

/* new uImage format support */
#define CONFIG_FIT
#define CONFIG_FIT_VERBOSE	/* enable fit_format_{error,warning}() */

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_FSL
#define CONFIG_SYS_FSL_I2C_SPEED	400000
#define CONFIG_SYS_FSL_I2C_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C_OFFSET	0x3000
#define CONFIG_SYS_FSL_I2C2_SPEED	400000
#define CONFIG_SYS_FSL_I2C2_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C2_OFFSET	0x3100
#define CONFIG_SYS_I2C_NOPROBES		{ {0, 0x29} }
#define CONFIG_SYS_I2C_EEPROM_ADDR	0x52
#define CONFIG_SYS_SPD_BUS_NUM		1 /* For rom_loc and flash bank */
/*
 * I2C2 EEPROM
 */
#undef CONFIG_ID_EEPROM

#define CONFIG_RTC_PT7C4338
#define CONFIG_SYS_I2C_RTC_ADDR		0x68
#define CONFIG_SYS_I2C_PCA9557_ADDR	0x18

/* enable read and write access to EEPROM */
#define CONFIG_CMD_EEPROM
#define CONFIG_SYS_I2C_MULTI_EEPROMS
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN 1
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS 3
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS 5

/*
 * eSPI - Enhanced SPI
 */
#define CONFIG_HARD_SPI
#define CONFIG_FSL_ESPI

#if defined(CONFIG_SPI_FLASH)
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_CMD_SF
#define CONFIG_SF_DEFAULT_SPEED	10000000
#define CONFIG_SF_DEFAULT_MODE	0
#endif

#if defined(CONFIG_PCI)
/*
 * General PCI
 * Memory space is mapped 1-1, but I/O space must start from 0.
 */

/* controller 2, direct to uli, tgtid 2, Base address 9000 */
#if defined(FSL_CONFIG_SOC)
#define CONFIG_SYS_PCIE2_NAME		"PCIe SLOT"
#define CONFIG_SYS_PCIE2_MEM_VIRT	0xa0000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE2_MEM_BUS	0xc0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xc20000000ull
#else
#define CONFIG_SYS_PCIE2_MEM_BUS	0xa0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xa0000000
#endif
#define CONFIG_SYS_PCIE2_MEM_SIZE	0x20000000	/* 512M */
#define CONFIG_SYS_PCIE2_IO_VIRT	0xffc10000
#define CONFIG_SYS_PCIE2_IO_BUS		0x00000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE2_IO_PHYS	0xfffc10000ull
#else
#define CONFIG_SYS_PCIE2_IO_PHYS	0xffc10000
#endif
#define CONFIG_SYS_PCIE2_IO_SIZE	0x00010000	/* 64k */

/* controller 1, Slot 2, tgtid 1, Base address a000 */
#define CONFIG_SYS_PCIE1_NAME		"mini PCIe SLOT"
#define CONFIG_SYS_PCIE1_MEM_VIRT	0x80000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE1_MEM_BUS	0x80000000
#define CONFIG_SYS_PCIE1_MEM_PHYS	0xc00000000ull
#else
#define CONFIG_SYS_PCIE1_MEM_BUS	0x80000000
#define CONFIG_SYS_PCIE1_MEM_PHYS	0x80000000
#endif
#define CONFIG_SYS_PCIE1_MEM_SIZE	0x20000000	/* 512M */
#define CONFIG_SYS_PCIE1_IO_VIRT	0xffc00000
#define CONFIG_SYS_PCIE1_IO_BUS		0x00000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE1_IO_PHYS	0xfffc00000ull
#else
#define CONFIG_SYS_PCIE1_IO_PHYS	0xffc00000
#endif
#define CONFIG_SYS_PCIE1_IO_SIZE	0x00010000	/* 64k */

#define CONFIG_PCI_PNP	/* do pci plug-and-play */
#define CONFIG_E1000	/* Defind e1000 pci Ethernet card*/
#define CONFIG_CMD_PCI
/*#define CONFIG_CMD_NET*/

#define CONFIG_PCI_SCAN_SHOW	/* show pci devices on startup */
#define CONFIG_DOS_PARTITION
#else
#define CONFIG_SYS_PCIE2_NAME		"PCIe-FLASH"
#define CONFIG_SYS_PCIE2_MEM_VIRT	0xa0000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE2_MEM_BUS	0xc0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xc20000000ull
#else
#define CONFIG_SYS_PCIE2_MEM_BUS	0xa0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xa0000000
#endif
#define CONFIG_SYS_PCIE2_MEM_SIZE	0x08000000	/* 128M */
#define CONFIG_SYS_PCIE2_IO_VIRT	0xffc80000
#define CONFIG_SYS_PCIE2_IO_BUS		0x00000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE2_IO_PHYS	0xfffc10000ull
#else
#define CONFIG_SYS_PCIE2_IO_PHYS	0xffc80000
#endif
#define CONFIG_SYS_PCIE2_IO_SIZE	0x00010000	/* 64k */

/* controller 1, Slot 2, tgtid 1, Base address a000 */
#define CONFIG_SYS_PCIE1_NAME		"PCIe-IO-BUS"
#define CONFIG_SYS_PCIE1_MEM_VIRT	0x80000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE1_MEM_BUS	0x80000000
#define CONFIG_SYS_PCIE1_MEM_PHYS	0xc00000000ull
#else
#define CONFIG_SYS_PCIE1_MEM_BUS	0x80000000
#define CONFIG_SYS_PCIE1_MEM_PHYS	0x80000000
#endif
#define CONFIG_SYS_PCIE1_MEM_SIZE	0x08000000	/* 128M */
#define CONFIG_SYS_PCIE1_IO_VIRT	0xffc00000
#define CONFIG_SYS_PCIE1_IO_BUS		0x00000000
#ifdef CONFIG_PHYS_64BIT
#define CONFIG_SYS_PCIE1_IO_PHYS	0xfffc00000ull
#else
#define CONFIG_SYS_PCIE1_IO_PHYS	0xffc00000
#endif
#define CONFIG_SYS_PCIE1_IO_SIZE	0x00010000	/* 64k */

#define CONFIG_PCI_PNP	/* do pci plug-and-play */
#define CONFIG_CMD_PCI
/*#define CONFIG_CMD_NET*/

#define CONFIG_PCI_SCAN_SHOW	/* show pci devices on startup */
#define CONFIG_DOS_PARTITION
/*pcie inbound*/


#if 0
#if defined(PM_CONFIG_SOC)
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_BUS     0
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_PHYS    0x10000000
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_SIZE    0x200000
#endif

#define CONFIG_SYS_PCI_MEMORY_IO_BUS     0x300000
#define CONFIG_SYS_PCI_MEMORY_IO_PHYS    0x11000000
#define CONFIG_SYS_PCI_MEMORY_IO_SIZE    0x100000
#endif
#endif

#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_BUS     0x300000
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_PHYS    0x1fc00000
/*
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_PHYS    0x11000000
*/
#define CONFIG_SYS_PCI_MEMORY_SPI_FLASH_SIZE    0x200000

#define CONFIG_SYS_PCI_MEMORY_IO_BUS     0x0
#define CONFIG_SYS_PCI_MEMORY_IO_PHYS    0x1fa00000
/*
#define CONFIG_SYS_PCI_MEMORY_IO_PHYS    0x10000000
*/
#define CONFIG_SYS_PCI_MEMORY_IO_SIZE    0x200000

#endif /* CONFIG_PCI */

#if defined(CONFIG_TSEC_ENET)
#define CONFIG_MII		/* MII PHY management */
#define CONFIG_TSEC1
#define CONFIG_TSEC1_NAME	"eTSEC1"
#define CONFIG_TSEC2
#define CONFIG_TSEC2_NAME	"eTSEC2"
#define CONFIG_TSEC3
#define CONFIG_TSEC3_NAME	"eTSEC3"

#define TSEC1_PHY_ADDR	2
#define TSEC2_PHY_ADDR	0
#define TSEC3_PHY_ADDR	1

#define TSEC1_FLAGS	(TSEC_GIGABIT | TSEC_REDUCED)
#if !defined(FSL_CONFIG_SOC)
#define TSEC2_FLAGS	(TSEC_GIGABIT | TSEC_SGMII)
#define TSEC3_FLAGS	(TSEC_GIGABIT | TSEC_SGMII)
#else
#define TSEC2_FLAGS	(TSEC_GIGABIT | TSEC_REDUCED)
#define TSEC3_FLAGS	(TSEC_GIGABIT | TSEC_REDUCED)
#endif

#define TSEC1_PHYIDX	0
#define TSEC2_PHYIDX	0
#define TSEC3_PHYIDX	0

#define CONFIG_ETHPRIME	"eTSEC2"

#define CONFIG_PHY_GIGE	1	/* Include GbE speed/duplex detection */

#define CONFIG_HAS_ETH0
#define CONFIG_HAS_ETH1
#define CONFIG_HAS_ETH2
#endif /* CONFIG_TSEC_ENET */

#ifdef CONFIG_QE
/* QE microcode/firmware address */
#define CONFIG_SYS_QE_FMAN_FW_IN_NOR
#define CONFIG_SYS_QE_FW_ADDR	0xefec0000
#define CONFIG_SYS_QE_FMAN_FW_LENGTH	0x10000
#endif /* CONFIG_QE */

#ifdef CONFIG_P1025RDB
/*
 * QE UEC ethernet configuration
 */
#define CONFIG_MIIM_ADDRESS	(CONFIG_SYS_CCSRBAR + 0x82120)

#undef CONFIG_UEC_ETH
#define CONFIG_PHY_MODE_NEED_CHANGE

#define CONFIG_UEC_ETH1	/* ETH1 */
#define CONFIG_HAS_ETH0

#ifdef CONFIG_UEC_ETH1
#define CONFIG_SYS_UEC1_UCC_NUM	0	/* UCC1 */
#define CONFIG_SYS_UEC1_RX_CLK	QE_CLK12 /* CLK12 for MII */
#define CONFIG_SYS_UEC1_TX_CLK	QE_CLK9 /* CLK9 for MII */
#define CONFIG_SYS_UEC1_ETH_TYPE	FAST_ETH
#define CONFIG_SYS_UEC1_PHY_ADDR	0x0	/* 0x0 for MII */
#define CONFIG_SYS_UEC1_INTERFACE_TYPE PHY_INTERFACE_MODE_RMII
#define CONFIG_SYS_UEC1_INTERFACE_SPEED	100
#endif /* CONFIG_UEC_ETH1 */

#define CONFIG_UEC_ETH5	/* ETH5 */
#define CONFIG_HAS_ETH1

#ifdef CONFIG_UEC_ETH5
#define CONFIG_SYS_UEC5_UCC_NUM	4	/* UCC5 */
#define CONFIG_SYS_UEC5_RX_CLK	QE_CLK_NONE
#define CONFIG_SYS_UEC5_TX_CLK	QE_CLK13 /* CLK 13 for RMII */
#define CONFIG_SYS_UEC5_ETH_TYPE	FAST_ETH
#define CONFIG_SYS_UEC5_PHY_ADDR	0x3	/* 0x3 for RMII */
#define CONFIG_SYS_UEC5_INTERFACE_TYPE PHY_INTERFACE_MODE_RMII
#define CONFIG_SYS_UEC5_INTERFACE_SPEED	100
#endif /* CONFIG_UEC_ETH5 */
#endif /* CONFIG_P1025RDB */

/*
 * Environment
 */
#ifdef CONFIG_SPIFLASH
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SPI_BUS	0
#define CONFIG_ENV_SPI_CS	0
#define CONFIG_ENV_SPI_MAX_HZ	10000000
#define CONFIG_ENV_SPI_MODE	0
#define CONFIG_ENV_SIZE		0x2000	/* 8KB */
#define CONFIG_ENV_OFFSET	0x100000	/* 1MB */
#define CONFIG_ENV_SECT_SIZE	0x10000
#elif defined(CONFIG_SDCARD)
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_FSL_FIXED_MMC_LOCATION
#define CONFIG_ENV_SIZE		0x2000
#define CONFIG_SYS_MMC_ENV_DEV	0
#elif defined(CONFIG_NAND)
#ifdef CONFIG_TPL_BUILD
#define CONFIG_ENV_SIZE		0x2000
#define CONFIG_ENV_ADDR		(CONFIG_SYS_INIT_L2_ADDR + (160 << 10))
#else
#define CONFIG_ENV_SIZE		CONFIG_SYS_NAND_BLOCK_SIZE
#endif
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET	(1024 * 1024)
#define CONFIG_ENV_RANGE	(3 * CONFIG_ENV_SIZE)
#elif defined(CONFIG_SYS_RAMBOOT)
#define CONFIG_ENV_IS_NOWHERE	/* Store ENV in memory only */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE - 0x1000)
#define CONFIG_ENV_SIZE		0x2000
#else
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_ADDR	(CONFIG_SYS_MONITOR_BASE - CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE		0x2000
#define CONFIG_ENV_SECT_SIZE	0x20000 /* 128K (one sector) */
#endif

#define CONFIG_LOADS_ECHO		/* echo on for serial download */
#define CONFIG_SYS_LOADS_BAUD_CHANGE	/* allow baudrate change */

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_IRQ
#define CONFIG_CMD_PING
#define CONFIG_CMD_I2C
#define CONFIG_CMD_MII
#define CONFIG_CMD_DATE
#define CONFIG_CMD_ELF
#define CONFIG_CMD_SETEXPR
#define CONFIG_CMD_REGINFO

/*
 * USB
 */
#define CONFIG_HAS_FSL_DR_USB

#if defined(CONFIG_HAS_FSL_DR_USB)
#define CONFIG_USB_EHCI

#ifdef CONFIG_USB_EHCI
#define CONFIG_CMD_USB
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_USB_EHCI_FSL
#define CONFIG_USB_STORAGE
#endif
#endif

#if defined(CONFIG_P1020RDB_PD)
#define CONFIG_USB_MAX_CONTROLLER_COUNT	1
#endif

#define CONFIG_MMC

#ifdef CONFIG_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	CONFIG_SYS_MPC85xx_ESDHC_ADDR
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#endif

#if defined(CONFIG_MMC) || defined(CONFIG_USB_EHCI) \
		 || defined(CONFIG_FSL_SATA)
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#endif

#undef CONFIG_WATCHDOG	/* watchdog disabled */

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP			/* undef to save memory */
#define CONFIG_CMDLINE_EDITING			/* Command-line editing */
#define CONFIG_SYS_LOAD_ADDR	0x2000000	/* default load address */
#if defined(CONFIG_CMD_KGDB)
#define CONFIG_SYS_CBSIZE	1024		/* Console I/O Buffer Size */
#else
#define CONFIG_SYS_CBSIZE	256		/* Console I/O Buffer Size */
#endif
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE/* Boot Argument Buffer Size */

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 64 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ	(64 << 20)	/* Initial Memory for Linux*/
#define CONFIG_SYS_BOOTM_LEN	(64 << 20)	/* Increase max gunzip size */

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	230400	/* speed to run kgdb serial port */
#endif

/*
 * Environment Configuration
 */
#define CONFIG_HOSTNAME		unknown
#define CONFIG_ROOTPATH		"/opt/nfsroot"
#define CONFIG_BOOTFILE		"uImage"
#define CONFIG_UBOOTPATH	u-boot.bin /* U-Boot image on TFTP server */

/* default location for tftp and bootm */
#define CONFIG_LOADADDR	1000000

#define CONFIG_BOOTDELAY 10	/* -1 disables auto-boot */
#define CONFIG_BOOTARGS	/* the boot command will set bootargs */

#define CONFIG_BAUDRATE	115200

#ifdef __SW_BOOT_NOR
#define __NOR_RST_CMD	\
norboot=i2c dev 1; i2c mw 18 1 __SW_BOOT_NOR 1; \
i2c mw 18 3 __SW_BOOT_MASK 1; reset
#endif
#ifdef __SW_BOOT_SPI
#define __SPI_RST_CMD	\
spiboot=i2c dev 1; i2c mw 18 1 __SW_BOOT_SPI 1; \
i2c mw 18 3 __SW_BOOT_MASK 1; reset
#endif
#ifdef __SW_BOOT_SD
#define __SD_RST_CMD	\
sdboot=i2c dev 1; i2c mw 18 1 __SW_BOOT_SD 1; \
i2c mw 18 3 __SW_BOOT_MASK 1; reset
#endif
#ifdef __SW_BOOT_NAND
#define __NAND_RST_CMD	\
nandboot=i2c dev 1; i2c mw 18 1 __SW_BOOT_NAND 1; \
i2c mw 18 3 __SW_BOOT_MASK 1; reset
#endif
#ifdef __SW_BOOT_PCIE
#define __PCIE_RST_CMD	\
pciboot=i2c dev 1; i2c mw 18 1 __SW_BOOT_PCIE 1; \
i2c mw 18 3 __SW_BOOT_MASK 1; reset
#endif

#define	CONFIG_EXTRA_ENV_SETTINGS	\
"netdev=eth1\0"	\
"uboot=" __stringify(CONFIG_UBOOTPATH) "\0"	\
"loadaddr=1000000\0"	\
"bootfile=uImage\0"	\
"tftpflash=tftpboot $loadaddr $uboot; "	\
	"protect off " __stringify(CONFIG_SYS_TEXT_BASE) " +$filesize; " \
	"erase " __stringify(CONFIG_SYS_TEXT_BASE) " +$filesize; "	\
	"cp.b $loadaddr " __stringify(CONFIG_SYS_TEXT_BASE) " $filesize; " \
	"protect on " __stringify(CONFIG_SYS_TEXT_BASE) " +$filesize; "	\
	"cmp.b $loadaddr " __stringify(CONFIG_SYS_TEXT_BASE) " $filesize\0" \
"hwconfig=usb1:dr_mode=host,phy_type=ulpi\0"    \
"consoledev=ttyS0\0"	\
"ramdiskaddr=2000000\0"	\
"ramdiskfile=rootfs.ext2.gz.uboot\0"	\
"fdtaddr=c00000\0"	\
"bdev=sda1\0" \
"jffs2nor=mtdblock3\0"	\
"norbootaddr=ef080000\0"	\
"norfdtaddr=ef040000\0"	\
"jffs2nand=mtdblock9\0"	\
"nandbootaddr=100000\0"	\
"nandfdtaddr=80000\0"		\
"ramdisk_size=120000\0"	\
"map_lowernorbank=i2c dev 1; i2c mw 18 1 02 1; i2c mw 18 3 fd 1\0" \
"map_uppernorbank=i2c dev 1; i2c mw 18 1 00 1; i2c mw 18 3 fd 1\0" \
__stringify(__NOR_RST_CMD)"\0" \
__stringify(__SPI_RST_CMD)"\0" \
__stringify(__SD_RST_CMD)"\0" \
__stringify(__NAND_RST_CMD)"\0" \
__stringify(__PCIE_RST_CMD)"\0"

#define CONFIG_NFSBOOTCOMMAND	\
"setenv bootargs root=/dev/nfs rw "	\
"nfsroot=$serverip:$rootpath "	\
"ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname:$netdev:off " \
"console=$consoledev,$baudrate $othbootargs;" \
"tftp $loadaddr $bootfile;"	\
"tftp $fdtaddr $fdtfile;"	\
"bootm $loadaddr - $fdtaddr"

#define CONFIG_HDBOOT	\
"setenv bootargs root=/dev/$bdev rw rootdelay=30 "	\
"console=$consoledev,$baudrate $othbootargs;" \
"usb start;"	\
"ext2load usb 0:1 $loadaddr /boot/$bootfile;"	\
"ext2load usb 0:1 $fdtaddr /boot/$fdtfile;"	\
"bootm $loadaddr - $fdtaddr"

#define CONFIG_USB_FAT_BOOT	\
"setenv bootargs root=/dev/ram rw "	\
"console=$consoledev,$baudrate $othbootargs " \
"ramdisk_size=$ramdisk_size;"	\
"usb start;"	\
"fatload usb 0:2 $loadaddr $bootfile;"	\
"fatload usb 0:2 $fdtaddr $fdtfile;"	\
"fatload usb 0:2 $ramdiskaddr $ramdiskfile;"	\
"bootm $loadaddr $ramdiskaddr $fdtaddr"

#define CONFIG_USB_EXT2_BOOT	\
"setenv bootargs root=/dev/ram rw "	\
"console=$consoledev,$baudrate $othbootargs " \
"ramdisk_size=$ramdisk_size;"	\
"usb start;"	\
"ext2load usb 0:4 $loadaddr $bootfile;"	\
"ext2load usb 0:4 $fdtaddr $fdtfile;" \
"ext2load usb 0:4 $ramdiskaddr $ramdiskfile;" \
"bootm $loadaddr $ramdiskaddr $fdtaddr"

#define CONFIG_NORBOOT	\
"setenv bootargs root=/dev/$jffs2nor rw "	\
"console=$consoledev,$baudrate rootfstype=jffs2 $othbootargs;"	\
"bootm $norbootaddr - $norfdtaddr"

#define CONFIG_RAMBOOTCOMMAND	\
"setenv bootargs root=/dev/ram rw "	\
"console=$consoledev,$baudrate $othbootargs " \
"ramdisk_size=$ramdisk_size;"	\
"tftp $ramdiskaddr $ramdiskfile;"	\
"tftp $loadaddr $bootfile;"	\
"tftp $fdtaddr $fdtfile;"	\
"bootm $loadaddr $ramdiskaddr $fdtaddr"

#if 1
#define CORE1_NOR_FROM 0xefb40000
#define CORE1_NOR_TO 0x1E00000
#define CORE_LEN 0x40000
#define CORE0_NOR_FROM 0xefd40000
#define CORE0_NOR_TO 0x100000

#define Z_TSEC eTSEC3
#define Z_SER_IP 192.168.0.111
#define Z_CLI_IP 192.168.0.168
#define ROOTFS_NAME cag_p1020_rootfs.ext4.z
#define P1020_BOOT    pmboot_dev.bin
#define P1020_UIMAGE      uImage_dev
#define P1020_DTB       p1020_dev.dtb
/*before use bootos0,bootos1,downub,burnub,you should configure ipaddr and serverip first or they will not work //ezio 10.29*/
#define CFG_NETWORK \
"setenv ipaddr " __stringify(Z_CLI_IP) " ;" \
"setenv serverip " __stringify(Z_SER_IP) " ; " \
"setenv ethaddr 00:04:9F:02:00:3c; " \
"setenv eth1addr 00:04:9F:02:00:3d; " \
"setenv eth2addr 00:04:9F:02:00:3e ;" \
"setenv ethact " __stringify(Z_TSEC) " ;" \
"setenv ethprime " __stringify(Z_TSEC) " ;"

#define NET_SET_CFG \
"setenv ipaddr " __stringify(Z_CLI_IP) " ;" \
"setenv serverip " __stringify(Z_SER_IP) " ; " \
"setenv ethaddr 00:04:9F:02:00:3c; " \
"setenv eth1addr 00:04:9F:02:00:3d; " \
"setenv eth2addr 00:04:9F:02:00:3e ;" \
"setenv ethact " __stringify(Z_TSEC) " ;" \
"setenv ethprime " __stringify(Z_TSEC) " ;"\
"tftp 0x1000000 " __stringify(P1020_BOOT) " ;"

#define BURN_UBOOT  \
"protect off eff40000 +0xc0000 ;" \
"erase 0xeff40000 +0xc0000 ;" \
"cp.b 1000000 eff40000 $filesize ;"

#define TFTP_LINUX0 \
"setenv ipaddr " __stringify(Z_CLI_IP) " ;" \
"setenv serverip " __stringify(Z_SER_IP) " ; " \
"setenv ethaddr 00:04:9F:02:00:3c; " \
"setenv eth1addr 00:04:9F:02:00:3d; " \
"setenv eth2addr 00:04:9F:02:00:3e ;" \
"setenv ethact " __stringify(Z_TSEC) " ;" \
"setenv ethprime " __stringify(Z_TSEC) " ;"\
"tftp 0x1000000 " __stringify(P1020_UIMAGE) " ;" \
"tftp 0x2000000 " __stringify(ROOTFS_NAME) " ;" \
"tftp 0x3000000 " __stringify(P1020_DTB) " ;" \
"bootm 0x1000000 0x2000000 0x3000000;"

#define NOR_LIN0 \
"echo load ramdisk;" \
"cp.b ef600000 2000000 400000 ;" \
"echo load uImage;" \
"cp.b ef020000 1000000 500000 ;" \
"echo load dtb;" \
"cp.b ef000000 3000000 4000 ;" \
"echo booting;" \
"bootm 0x1000000 0x2000000 0x3000000 ;"

#define BURN_LINUX0 \
"setenv ipaddr " __stringify(Z_CLI_IP) " ;" \
"setenv serverip " __stringify(Z_SER_IP) " ; " \
"setenv ethaddr 00:04:9F:02:00:3c; " \
"setenv eth1addr 00:04:9F:02:00:3d; " \
"setenv eth2addr 00:04:9F:02:00:3e ;" \
"setenv ethact " __stringify(Z_TSEC) " ;" \
"setenv ethprime " __stringify(Z_TSEC) " ;"\
"tftp 0x1000000 " __stringify(P1020_UIMAGE) " ;" \
"tftp 0x2000000 " __stringify(ROOTFS_NAME) " ;" \
"tftp 0x3000000 " __stringify(P1020_DTB) " ;" \
"protect off ef000000 +0x100000 ;" \
"echo burn dtb;" \
"erase 0xef000000 +0x20000 ;" \
"cp.b 3000000  ef000000 4000 ;" \
"echo burn kernel;" \
"erase 0xef020000 +0x500000 ;" \
"cp.b 1000000 ef020000 500000 ;" \
"echo burn rootfs;" \
"erase 0xef600000 +0x400000 ;" \
"cp.b 2000000 ef600000 400000;"

#define NOR_ROOTFS_LIN0 \
"echo boot disk flash;" \
"echo load uImage;" \
"cp.b ef020000 1000000 500000 ;" \
"echo load dtb;" \
"cp.b ef000000 3000000 4000 ;" \
"echo booting;" \
"bootm 0x1000000 - 0x3000000 ;"

#define NOR_BOOT_CAG0 \
"echo boot cagos in core 0;" \
"echo from " __stringify(CORE0_NOR_FROM) " to " __stringify(CORE0_NOR_TO) " len " __stringify(CORE_LEN)";" \
"cp " __stringify(CORE0_NOR_FROM) " " __stringify(CORE0_NOR_TO) " " __stringify(CORE_LEN)";" \
"go 0x100020;"

#define NOR_BOOT_CAG1 \
"echo boot cagos in core 1;" \
"cp " __stringify(CORE1_NOR_FROM) " " __stringify(CORE1_NOR_TO) " " __stringify(CORE_LEN)" ;" \
"cpu 1 release 0x1e00020 - - -;" \
"cpu 1 release 0x1e00020 - - -;" \
"echo core1 stated ;" \

#define BOOT_CORE01 \
"echo boot cagos in core 1;" \
"cp " __stringify(CORE1_NOR_FROM) " " __stringify(CORE1_NOR_TO) " " __stringify(CORE_LEN)" ;" \
"cpu 1 release 0x1e00020 - - -;" \
"cpu 1 release 0x1e00020 - - -;" \
"echo core1 stated ;" \
"echo boot cagos in core 0;" \
"echo from " __stringify(CORE0_NOR_FROM) " to " __stringify(CORE0_NOR_TO) " len " __stringify(CORE_LEN)";" \
"cp " __stringify(CORE0_NOR_FROM) " " __stringify(CORE0_NOR_TO) " " __stringify(CORE_LEN)";" \
"go 0x100020;"


#endif

#define CONFIG_BOOTCOMMAND	BOOT_CORE01 /*NOR_BOOT_CAG0NOR_LIN0//CONFIG_HDBOOT*/

#endif /* __CONFIG_H */
