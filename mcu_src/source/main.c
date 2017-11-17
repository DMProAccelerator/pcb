#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "communicator.h"

void reset_blink() {
	volatile long i;
	GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 1);
	for(i = 0; i < 1000000; i++);
	GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 0);
}

int main(void) {
	CHIP_Init();
	CMU_ClockEnable(cmuClock_GPIO, true);

	reset_blink();
	setup_project();

	return 0;
}
