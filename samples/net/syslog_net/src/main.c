/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(net_syslog, LOG_LEVEL_DBG);

#include <zephyr.h>

#include <net/net_core.h>
#include <net/net_pkt.h>

BUILD_ASSERT(IS_ENABLED(CONFIG_LOG_BACKEND_NET), "syslog backend not enabled");

#define SLEEP_BETWEEN_PRINTS 3

void main(void)
{
	int count = 60 / SLEEP_BETWEEN_PRINTS;

	/* Allow some setup time before starting to send data */
	k_sleep(K_SECONDS(SLEEP_BETWEEN_PRINTS));

	LOG_DBG("Starting");

	do {
		LOG_ERR("Error message");
		LOG_WRN("Warning message");
		LOG_INF("Info message");
		LOG_DBG("Debug message");

		k_sleep(K_SECONDS(SLEEP_BETWEEN_PRINTS));

	} while (count--);

	LOG_DBG("Stopping");
}
