/*
 * ICP DAS LP-8x4x configuration file
 *
 * Copyright (C) 2013 Sergey Yanovich <ynvich@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef	__CONFIG_H
#define	__CONFIG_H

/*
 * High Level Board Configuration Options
 */
#define	CONFIG_CPU_PXA27X			/* Marvell PXA270 CPU */
#define	MACH_TYPE_LP8X4X		4539	/* ICP DAS LP-8x4x */
#define	CONFIG_MACH_TYPE		MACH_TYPE_LP8X4X
#define	CONFIG_SYS_TEXT_BASE		0x00000000

#define	CONFIG_SYS_MALLOC_LEN		(128*1024)
#define	CONFIG_ARCH_CPU_INIT
#define	CONFIG_BOOTCOMMAND		\
	"bootm 80000 - 240000;"

#define	CONFIG_BOOTARGS			\
	"console=ttyS0,115200 mem=128M root=/dev/mmcblk0p1 rw" \
	"init=/sbin/init rootfstype=ext4 rootwait"

#define	CONFIG_TIMESTAMP
#define	CONFIG_BOOTDELAY		2	/* Autoboot delay */
#define	CONFIG_CMDLINE_TAG
#define	CONFIG_SETUP_MEMORY_TAGS
#define	CONFIG_LZMA			/* LZMA compression support */
#define	CONFIG_OF_LIBFDT

/*
 * Serial Console Configuration
 */
#define	CONFIG_PXA_SERIAL
#define	CONFIG_FFUART			1
#define	CONFIG_CONS_INDEX		3
#define	CONFIG_BAUDRATE			115200

/*
 * Bootloader Components Configuration
 */
#include <config_cmd_default.h>

#define	CONFIG_CMD_NET
#define	CONFIG_CMD_ENV
#undef	CONFIG_CMD_IMLS
#define	CONFIG_CMD_MMC
#define	CONFIG_CMD_USB
#undef	CONFIG_LCD
#undef	CONFIG_CMD_IDE

/*
 * Networking Configuration
 * chip on the ICPDAS LINPAC board
 */
#ifdef	CONFIG_CMD_NET
#define	CONFIG_CMD_PING
#define	CONFIG_CMD_DHCP

#define	CONFIG_DRIVER_DM9000		1
#define	CONFIG_DM9000_BASE		0x0C000000
#define	DM9000_IO			0x0C000000
#define	DM9000_DATA			0x0C004000
#define	DM9000_IO_2			0x0D000000
#define	DM9000_DATA_2			0x0D004000
#define	CONFIG_NET_RETRY_COUNT		10

#define	CONFIG_BOOTP_BOOTFILESIZE
#define	CONFIG_BOOTP_BOOTPATH
#define	CONFIG_BOOTP_GATEWAY
#define	CONFIG_BOOTP_HOSTNAME
#endif

/*
 * MMC Card Configuration
 */
#ifdef	CONFIG_CMD_MMC
#define	CONFIG_MMC
#define	CONFIG_GENERIC_MMC
#define	CONFIG_PXA_MMC_GENERIC
#define	CONFIG_CMD_FAT
#define	CONFIG_CMD_EXT2
#define	CONFIG_DOS_PARTITION
#endif

/*
 * KGDB
 */
#ifdef	CONFIG_CMD_KGDB
#define	CONFIG_KGDB_BAUDRATE		230400	/* kgdb serial port speed */
#endif

/*
 * HUSH Shell Configuration
 */
#define	CONFIG_SYS_HUSH_PARSER		1

#define	CONFIG_SYS_LONGHELP
#ifdef	CONFIG_SYS_HUSH_PARSER
#define	CONFIG_SYS_PROMPT		"$ "
#else
#endif
#define	CONFIG_SYS_CBSIZE		256
#define	CONFIG_SYS_PBSIZE		\
	(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define	CONFIG_SYS_MAXARGS		16
#define	CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define	CONFIG_SYS_DEVICE_NULLDEV	1
#define	CONFIG_CMDLINE_EDITING		1
#define	CONFIG_AUTO_COMPLETE		1

/*
 * DRAM Map
 */
#define	CONFIG_NR_DRAM_BANKS		1		/* 1 bank of DRAM */
#define	PHYS_SDRAM_1			0xa0000000	/* SDRAM Bank #1 */
#define	PHYS_SDRAM_1_SIZE		0x08000000	/* 128 MB */

#define	CONFIG_SYS_DRAM_BASE		0xa0000000	/* CS0 */
#define	CONFIG_SYS_DRAM_SIZE		0x08000000	/* 128 MB DRAM */

#define	CONFIG_SYS_MEMTEST_START	0xa0400000	/* memtest works on */
#define	CONFIG_SYS_MEMTEST_END		0xa0800000	/* 4 ... 8 MB in DRAM */

#define	CONFIG_SYS_LOAD_ADDR		0xa0008000
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
/* Use first 64kb bank of the internal SRAM */
#define	CONFIG_SYS_INIT_SP_ADDR		0x5c010000

/*
 * NOR FLASH
 */
#define	CONFIG_SYS_MONITOR_BASE		0x0
#define	CONFIG_SYS_MONITOR_LEN		0x40000
#define	CONFIG_ENV_ADDR			\
			(CONFIG_SYS_MONITOR_BASE + CONFIG_SYS_MONITOR_LEN)
#define	CONFIG_ENV_SIZE			0x40000
#define	CONFIG_ENV_SECT_SIZE		0x40000

#define	PHYS_FLASH_1			0x00000000	/* Flash Bank #1 */
#define	PHYS_FLASH_2			0x04000000	/* Flash Bank #2 */

#define	CONFIG_SYS_FLASH_CFI
#define	CONFIG_FLASH_CFI_DRIVER		1

#define	CONFIG_SYS_MAX_FLASH_SECT	(4 + 255)
#define	CONFIG_SYS_MAX_FLASH_BANKS	2
#define	CONFIG_SYS_FLASH_BANKS_LIST	{ PHYS_FLASH_1, PHYS_FLASH_2 }

#define	CONFIG_SYS_FLASH_ERASE_TOUT	(25*CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_WRITE_TOUT	(25*CONFIG_SYS_HZ)

#define	CONFIG_SYS_FLASH_USE_BUFFER_WRITE	1
#define	CONFIG_SYS_FLASH_PROTECTION		1

#define	CONFIG_ENV_IS_IN_FLASH		1

/*
 * GPIO settings
 */
#define	CONFIG_SYS_GPSR0_VAL	0x0808c014
#define	CONFIG_SYS_GPSR1_VAL	0x00cf0002
#define	CONFIG_SYS_GPSR2_VAL	0x0221c000
#define	CONFIG_SYS_GPSR3_VAL	0x00020000

#define	CONFIG_SYS_GPCR0_VAL	0x00000000
#define	CONFIG_SYS_GPCR1_VAL	0x0000ab80
#define	CONFIG_SYS_GPCR2_VAL	0x00100000
#define	CONFIG_SYS_GPCR3_VAL	0x0

#define	CONFIG_SYS_GPDR0_VAL	0xc0e9ddf4
#define	CONFIG_SYS_GPDR1_VAL	0xfcffab83
#define	CONFIG_SYS_GPDR2_VAL	0x02f1ffff
#define	CONFIG_SYS_GPDR3_VAL	0x00021b81

#define	CONFIG_SYS_GAFR0_L_VAL	0x80000000
#define	CONFIG_SYS_GAFR0_U_VAL	0xa5e54018
#define	CONFIG_SYS_GAFR1_L_VAL	0x999a955a
#define	CONFIG_SYS_GAFR1_U_VAL	0xaaa5a00a
#define	CONFIG_SYS_GAFR2_L_VAL	0xaaaaaaaa
#define	CONFIG_SYS_GAFR2_U_VAL	0x55f9a402
#define	CONFIG_SYS_GAFR3_L_VAL	0x540a950c
#define	CONFIG_SYS_GAFR3_U_VAL	0x00001599

#define	CONFIG_SYS_PSSR_VAL	0x32

/*
 * Clock settings
 */
#define	CONFIG_SYS_CKEN		0x005002c0
#define	CONFIG_SYS_CCCR		0x02000290
#define	CONFIG_SYS_CLKCFG	0x0000000b

/*
 * Memory settings
 */
#define	CONFIG_SYS_MSC0_VAL	0x2bd8aad2
#define	CONFIG_SYS_MSC1_VAL	0xb8c9b8dc
#define	CONFIG_SYS_MSC2_VAL	0xfff9b8c9
#define	CONFIG_SYS_FLYCNFG_VAL	0x00010001
#define	CONFIG_SYS_MDREFR_VAL	0x2093e018
#define	CONFIG_SYS_MDCNFG_VAL	0x890009d1
#define	CONFIG_SYS_MDMRS_VAL	0x00220022
#define	CONFIG_SYS_SXCNFG_VAL	0x40044004

/*
 * PCMCIA and CF Interfaces
 */
#define	CONFIG_SYS_MECR_VAL	0x00000001
#define	CONFIG_SYS_MCMEM0_VAL	0x0000c497
#define	CONFIG_SYS_MCMEM1_VAL	0x0000c497
#define	CONFIG_SYS_MCATT0_VAL	0x0000c497
#define	CONFIG_SYS_MCATT1_VAL	0x0000c497
#define	CONFIG_SYS_MCIO0_VAL	0x00008407
#define	CONFIG_SYS_MCIO1_VAL	0x00008407

/*
 * LCD
 */
#ifdef	CONFIG_LCD
#define	CONFIG_VOIPAC_LCD
#endif

/*
 * USB
 */
#ifdef	CONFIG_CMD_USB
#define	CONFIG_USB_OHCI_NEW
#define	CONFIG_SYS_USB_OHCI_BOARD_INIT
#define	CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2
#define	CONFIG_SYS_USB_OHCI_REGS_BASE	0x4C000000
#define	CONFIG_SYS_USB_OHCI_SLOT_NAME	"lp8x4x"
#define	CONFIG_USB_STORAGE
#endif

#endif	/* __CONFIG_H */