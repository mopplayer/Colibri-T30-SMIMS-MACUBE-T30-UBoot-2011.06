/*
 * Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 */

#include <common.h>

unsigned long timer_get_us(void)
{
	printf("%s() used but not implemented.\n", __func__);
	return 0;
}

ulong get_timer_masked(void)
{
	printf("%s() used but not implemented.\n", __func__);
	return 0;
}
