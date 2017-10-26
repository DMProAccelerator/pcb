#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

void GPIO_ODD_IRQHandler(void) {GPIO_IntClear(0x0200);}

/*int main(void) {
	CHIP_Init();
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_DriverModeSet(gpioPortE, gpioDriverModeLowest);
	GPIO_PinModeSet(gpioPortB, 9, gpioModeInput, 1);
	GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull 0);
	GPIO_PinModeSet(gpioPortE, 3, gpioModePushPullDrive, 0);
	NVIC_EnableIRQ(GPIO_ODD_IRQn);
	GPIO_IntConfig(gpioPortB, 9, false, true, true);

	while(1) {
		EMU_EnterEM3(false);
		GPIO_PortOutSet(gpioPortE, 0xC);
		while(!GPIO_PinInGet(gpioPortB, 9));
		GPIO_PortOutClear(gpioPortE, 0xC);
	}

	return 0;
}*/



/*int main(void) {
//	CHIP_Init();
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_DriveModeSet(gpioPortE, gpioDriveModeLowest);
	GPIO_PinModeSet(gpioPortB, 9, gpioModeInput, 1);
	GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 0);
	GPIO_PinModeSet(gpioPortE, 3, gpioModePushPullDrive, 0);
	NVIC_EnableIRQ(GPIO_ODD_IRQn);
	GPIO_IntConfig(gpioPortB, 9, false, true, true);
	while(1) {
		EMU_EnterEM3(false);
		GPIO_PortOutSet(gpioPortE, 0xC);
		while(!GPIO_PinInGet(gpioPortB, 9));
		GPIO_PortOutClear(gpioPortE, 0xC);
	}
}*/


int main(void) {
//	CHIP_Init();

	return 0;
}
