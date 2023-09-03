/*
 * Copyright (c) 2009-2012 NVIDIA Corporation
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
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

#include <common.h>
#include <usb.h>

#include "ehci.h"

#include <asm/errno.h>
#include <asm/arch/usb.h>

#if !defined(CONFIG_TEGRA3)
#define TEGRA_USB1_BASE		0xC5000000
#else
#define TEGRA_USB1_BASE		0x7D000000
#endif

/*
 * A known hardware issue where Connect Status Change bit of PORTSC register
 * of USB1 controller will be set after Port Reset.
 * We have to clear it in order for later device enumeration to proceed.
 * This ehci_powerup_fixup overrides the weak function ehci_powerup_fixup
 * in "ehci-hcd.c".
 */
void ehci_powerup_fixup(uint32_t *status_reg, uint32_t *reg)
{
	wait_ms(50);
	if (((u32) status_reg & TEGRA_USB_ADDR_MASK) != TEGRA_USB1_BASE)
		return;
	/* For EHCI_PS_CSC to be cleared in ehci_hcd.c */
	if (ehci_readl(status_reg) & EHCI_PS_CSC)
		*reg |= EHCI_PS_CSC;
}

/*
 * Create the appropriate control structures to manage
 * a new EHCI host controller.
 */
int ehci_hcd_init(int index, struct ehci_hccr **hccr, struct ehci_hcor **hcor)
{
	return tegrausb_start_port(index, hccr, hcor);
}

/*
 * Destroy the appropriate control structures corresponding
 * the the EHCI host controller.
 */
int ehci_hcd_stop(int index)
{
	usb_set_host_mode();
	tegrausb_stop_port(index);
	return 0;
}
