#include "spi_interface.h"

#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "spi.h"
#include "usart.h"

void init_spi() {
	CMU_ClockEnable(cmuClock_USART1, true);
	CMU_ClockEnable(cmuClock_GPIO, true);

	SPI_setup(USART1_NUM, GPIO_POS1, true);
}

void send_buffer(char *buffer, unsigned long size) {
	USART1_sendBuffer(buffer, size);
}
