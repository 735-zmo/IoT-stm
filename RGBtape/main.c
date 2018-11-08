/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       example application for setting a periodic wakeup
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 *
 * @}
 */

#include <stdio.h>
#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"
#include "thread.h"

/* set interval to 1 second */
#define INTERVAL (1 * US_PER_SEC)
#define INTERVAL2 (1 * US_PER_SEC)
#define INTERVAL3 (1 * US_PER_SEC)

char stack[THREAD_STACKSIZE_MAIN];
int mode = 0;

int main(void)
{
	// Инициализация переменной таймера
	xtimer_ticks32_t last_wakeup = xtimer_now();

	// Инициализая портов PC0-PC2
	gpio_init(GPIO_PIN(PORT_C, 0), GPIO_OUT);
	//gpio_init(GPIO_PIN(PORT_C, 7), GPIO_OUT);
	// gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT);
	gpio_init(GPIO_PIN(PORT_C, 1), GPIO_OUT);
	gpio_init(GPIO_PIN(PORT_C, 2), GPIO_OUT);




	while (1)
	{

		gpio_set(GPIO_PIN(PORT_C, 1));
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
		gpio_clear(GPIO_PIN(PORT_C, 1));

		gpio_set(GPIO_PIN(PORT_C, 2));
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
		gpio_clear(GPIO_PIN(PORT_C, 2));

		gpio_set(GPIO_PIN(PORT_C, 0));
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
		gpio_clear(GPIO_PIN(PORT_C, 0));

		// gpio_toggle(GPIO_PIN(PORT_C, 2));
		
	}
	
    return 0;
}
