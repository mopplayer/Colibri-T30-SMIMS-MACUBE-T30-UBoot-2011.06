# Copyright (c) 2012 Toradex, Inc.
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA

include $(TOPDIR)/config.mk

ifneq ($(OBJTREE),$(SRCTREE))
$(shell mkdir -p $(obj)../../nvidia/common/crypto)
endif

LIB	= $(obj)lib$(VENDOR).o

COBJS-y += board.o
COBJS-$(CONFIG_TEGRA2_NAND) += tegra2_nand.o
COBJS-y += tegra2_partitions.o
COBJS-$(CONFIG_USB_EHCI_TEGRA) += ulpi_linux.o
COBJS-$(CONFIG_USB_EHCI_TEGRA) += usb.o

COBJS-$(CONFIG_TEGRA_CLOCK_SCALING) += ../../nvidia/common/emc.o
COBJS-$(CONFIG_TEGRA_PMU) += ../../nvidia/common/pmu.o
COBJS-$(CONFIG_TEGRA_LP0) += ../../nvidia/common/crypto/aes_ref.o
COBJS-$(CONFIG_TEGRA_LP0) += ../../nvidia/common/crypto/crypto.o

COBJS	:= $(COBJS-y)
SRCS	:= $(SOBJS:.o=.S) $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS))
SOBJS	:= $(addprefix $(obj),$(SOBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS) $(SOBJS)
	$(call cmd_link_o_target, $(OBJS) $(SOBJS))

clean:
	rm -f $(SOBJS) $(OBJS)

distclean:	clean
	rm -f $(LIB) core *.bak $(obj).depend

#########################################################################
# This is for $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
