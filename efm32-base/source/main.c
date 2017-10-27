#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

#include "i2c.h"

volatile uint32_t msTicks;
void delay(uint32_t dlyTicks);
void SysTick_Handler(void) {msTicks++;}

void delay(uint32_t dlyTicks) {
    uint32_t curTicks;

    curTicks = msTicks;
    while ((msTicks - curTicks) < dlyTicks) ;
}

void blink() {
	volatile long i;
	volatile long sleep_time = 1000000;
	while(1) {
		GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 1);
		for(i = 0; i < sleep_time; i++);
		GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 0);
		for(i = 0; i < sleep_time; i++);
	}
}

void test_i2c() {
	enable_i2c_clocks();
	setupI2C();
	setupRTC();

	while(1) {
		if(i2c_rxInProgress)	{
			receiveI2CData();
		} else if(i2c_startTx)	{
			performI2CTransfer();
			i2c_startTx = false;
		}
		EMU_EnterEM2(false);
	}
}

int main(void) {
	CHIP_Init();
	CMU_ClockEnable(cmuClock_GPIO, true);
	test_i2c();
	//blink();
}



