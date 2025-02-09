/*
 * Freescale DMA Controller
 *
 * Copyright 2006 Freescale Semiconductor, Inc.
 *
 * This software may be used and distributed according to the
 * terms of the GNU Public License, Version 2, incorporated
 * herein by reference.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _ASM_FSL_DMA_H_
#define _ASM_FSL_DMA_H_

#include <libc/cagboot.h>
#include <p1020rdb.h>
#include <config.h>
#include <libc/stdio.h>


typedef struct fsl_dma {
	uint32_t	mr;		/* DMA mode register */
#define FSL_DMA_MR_CS		0x00000001	/* Channel start */
#define FSL_DMA_MR_CC		0x00000002	/* Channel continue */
#define FSL_DMA_MR_CTM		0x00000004	/* Channel xfer mode */
#define FSL_DMA_MR_CTM_DIRECT	0x00000004	/* Direct channel xfer mode */
#define FSL_DMA_MR_CA		0x00000008	/* Channel abort */
#define FSL_DMA_MR_CDSM		0x00000010
#define FSL_DMA_MR_XFE		0x00000020	/* Extended features en */
#define FSL_DMA_MR_EIE		0x00000040	/* Error interrupt en */
#define FSL_DMA_MR_EOLSIE	0x00000080	/* End-of-lists interrupt en */
#define FSL_DMA_MR_EOLNIE	0x00000100	/* End-of-links interrupt en */
#define FSL_DMA_MR_EOSIE	0x00000200	/* End-of-seg interrupt en */
#define FSL_DMA_MR_SRW		0x00000400	/* Single register write */
#define FSL_DMA_MR_SAHE		0x00001000	/* Source addr hold enable */
#define FSL_DMA_MR_DAHE		0x00002000	/* Dest addr hold enable */
#define FSL_DMA_MR_SAHTS_MASK	0x0000c000	/* Source addr hold xfer size */
#define FSL_DMA_MR_DAHTS_MASK	0x00030000	/* Dest addr hold xfer size */
#define FSL_DMA_MR_EMS_EN	0x00040000	/* Ext master start en */
#define FSL_DMA_MR_EMP_EN	0x00200000	/* Ext master pause en */
#define FSL_DMA_MR_BWC_MASK	0x0f000000	/* Bandwidth/pause ctl */
#define FSL_DMA_MR_BWC_DIS	0x0f000000	/* Bandwidth/pause ctl disable */
	uint32_t	sr;		/* DMA status register */
#define FSL_DMA_SR_EOLSI	0x00000001	/* End-of-list interrupt */
#define FSL_DMA_SR_EOSI		0x00000002	/* End-of-segment interrupt */
#define FSL_DMA_SR_CB		0x00000004	/* Channel busy */
#define FSL_DMA_SR_EOLNI	0x00000008	/* End-of-links interrupt */
#define FSL_DMA_SR_PE		0x00000010	/* Programming error */
#define FSL_DMA_SR_CH		0x00000020	/* Channel halted */
#define FSL_DMA_SR_TE		0x00000080	/* Transfer error */
	char	res0[4];
	uint32_t	clndar;		/* DMA current link descriptor address register */
	uint32_t	satr;		/* DMA source attributes register */
#define FSL_DMA_SATR_ESAD_MASK		0x000001ff	/* Extended source addr */
#define FSL_DMA_SATR_SREAD_NO_SNOOP	0x00040000	/* Read, don't snoop */
#define FSL_DMA_SATR_SREAD_SNOOP	0x00050000	/* Read, snoop */
#define FSL_DMA_SATR_SREAD_UNLOCK	0x00070000	/* Read, unlock l2 */
#define FSL_DMA_SATR_STRAN_MASK		0x00f00000	/* Source interface  */
#define FSL_DMA_SATR_SSME		0x01000000	/* Source stride en */
#define FSL_DMA_SATR_SPCIORDER		0x02000000	/* PCI transaction order */
#define FSL_DMA_SATR_STFLOWLVL_MASK	0x0c000000	/* RIO flow level */
#define FSL_DMA_SATR_SBPATRMU		0x20000000	/* Bypass ATMU */
	uint32_t	sar;		/* DMA source address register */
	uint32_t	datr;		/* DMA destination attributes register */
#define FSL_DMA_DATR_EDAD_MASK		0x000001ff	/* Extended dest addr */
#define FSL_DMA_DATR_DWRITE_NO_SNOOP	0x00040000	/* Write, don't snoop */
#define FSL_DMA_DATR_DWRITE_SNOOP	0x00050000	/* Write, snoop */
#define FSL_DMA_DATR_DWRITE_ALLOC	0x00060000	/* Write, alloc l2 */
#define FSL_DMA_DATR_DWRITE_LOCK	0x00070000	/* Write, lock l2 */
#define FSL_DMA_DATR_DTRAN_MASK		0x00f00000	/* Dest interface  */
#define FSL_DMA_DATR_DSME		0x01000000	/* Dest stride en */
#define FSL_DMA_DATR_DPCIORDER		0x02000000	/* PCI transaction order */
#define FSL_DMA_DATR_DTFLOWLVL_MASK	0x0c000000	/* RIO flow level */
#define FSL_DMA_DATR_DBPATRMU		0x20000000	/* Bypass ATMU */
	uint32_t	dar;		/* DMA destination address register */
	uint32_t	bcr;		/* DMA byte count register */
	char	res1[4];
	uint32_t	nlndar;		/* DMA next link descriptor address register */
	char	res2[8];
	uint32_t	clabdar;	/* DMA current List - alternate base descriptor address Register */
	char	res3[4];
	uint32_t	nlsdar;		/* DMA next list descriptor address register */
	uint32_t	ssr;		/* DMA source stride register */
	uint32_t	dsr;		/* DMA destination stride register */
	char	res4[56];
} fsl_dma_t;

/* DMA Registers(0x2_1000-0x2_2000) */
typedef struct ccsr_dma {
    char    res1[256];
    struct fsl_dma dma[4];
    uint32_t dgsr;       /* 0x21300 - DMA General Status Register */
    char    res2[3324];
} ccsr_dma_t;

void dma_init(void);
int dma_memcpy(phys_addr_t dest, phys_addr_t src, phys_size_t n);

#endif	/* _ASM_DMA_H_ */
