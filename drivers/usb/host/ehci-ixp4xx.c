/*
 * (C) Copyright 2008, Michael Trimarchi <trimarchimichael@yahoo.it>
 *
 * Author: Michael Trimarchi <trimarchimichael@yahoo.it>
 * This code is based on ehci freescale driver
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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
/*
 * Create the appropriate control structures to manage
 * a new EHCI host controller.
 */
int ehci_hcd_init(int index, struct ehci_hccr **ret_hccr,
		struct ehci_hcor **ret_hcor)
{
	struct ehci_hccr *hccr;
	struct ehci_hcor *hcor;

	hccr = (struct ehci_hccr *)(0xcd000100);
	hcor = (struct ehci_hcor *)((uint32_t) hccr
			+ HC_LENGTH(ehci_readl(&hccr->cr_capbase)));

	printf("IXP4XX init hccr %x and hcor %x hc_length %d\n",
		(uint32_t)hccr, (uint32_t)hcor,
		(uint32_t)HC_LENGTH(ehci_readl(&hccr->cr_capbase)));

	*ret_hccr = hccr;
	*ret_hcor = hcor;
	return 0;
}

/*
 * Destroy the appropriate control structures corresponding
 * the the EHCI host controller.
 */
int ehci_hcd_stop(int index)
{
	return 0;
}
