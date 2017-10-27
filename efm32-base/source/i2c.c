#include "i2c.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_rtc.h"
#include "em_emu.h"
#include "em_gpio.h"

#define RTC_MIN_TIMEOUT		32000
#define I2C_ADDRESS		0xE2
#define I2C_RXBUFFER_SIZE	10

uint8_t i2c_txBuffer[]		= "Gecko";
uint8_t i2c_txBufferSize	= sizeof(i2c_txBuffer);
uint8_t i2c_rxBuffer[I2C_RXBUFFER_SIZE];
uint8_t i2c_rxBufferIndex;

void enable_i2c_clocks() {
	CMU_ClockEnable(cmuClock_I2C0, true);
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockEnable(cmuClock_USART0, true);
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
	CMU_ClockEnable(cmuClock_RTC, true);
}

void enableI2CSlaveInterrupts() {
	I2C_IntClear(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
	I2C_IntEnable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
	NVIC_EnableIRQ(I2C0_IRQn);
}

void disableI2CInterrupts() {
	NVIC_DisableIRQ(I2C0_IRQn);
	I2C_IntDisable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
	I2C_IntClear(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
}

void setupI2C() {
	I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	//Orignially PD6 (SDA) PD7 (SCL)
	GPIO_PinModeSet(gpioPortC, 5, gpioModeWiredAndPullUpFilter, 1); //SCL
	GPIO_PinModeSet(gpioPortC, 4, gpioModeWiredAndPullUpFilter, 1);	//SDA

	GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 0);

	I2C0->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN | (1 << _I2C_ROUTE_LOCATION_SHIFT);

	I2C_Init(I2C0, &i2cInit);

	i2c_rxInProgress = false;
	i2c_startTx = false;
	i2c_rxBufferIndex = 0;

	I2C0->SADDR = I2C_ADDRESS;
	I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN;
	enableI2CSlaveInterrupts();
}

void receiveI2CData() {
	while(i2c_rxInProgress) EMU_EnterEM1();
}

void performI2CTransfer() {
	I2C_TransferSeq_TypeDef i2cTransfer;
	GPIO_PinOutSet(gpioPortC, 0);
	i2cTransfer.addr	= I2C_ADDRESS;
	i2cTransfer.flags	= I2C_FLAG_WRITE;
	i2cTransfer.buf[0].data	= i2c_txBuffer;
	i2cTransfer.buf[0].len	= i2c_txBufferSize;
	i2cTransfer.buf[1].data	= i2c_rxBuffer;
	i2cTransfer.buf[1].len	= I2C_RXBUFFER_SIZE;
	I2C_TransferInit(I2C0, &i2cTransfer);

	while(I2C_Transfer(I2C0) == i2cTransferInProgress);

	GPIO_PinOutClear(gpioPortC, 0);
	enableI2CSlaveInterrupts();
}

void setupRTC() {
	uint16_t rtcTimeout;
	RTC_Init_TypeDef rtcInit = RTC_INIT_DEFAULT;

	rtcTimeout = (*(uint32_t *)0xFE081F0);

	if(rtcTimeout < RTC_MIN_TIMEOUT) rtcTimeout += RTC_MIN_TIMEOUT;

	RTC_CompareSet(0, rtcTimeout);

	RTC_IntEnable(RTC_IFC_COMP0);
	NVIC_EnableIRQ(RTC_IRQn);

	RTC_Init(&rtcInit);
}

void RTC_IRQHandler() {
	RTC_IntClear(RTC_IFC_COMP0);
	if(!i2c_rxInProgress) {
		disableI2CInterrupts();
		i2c_startTx = true;
	}
}

void I2C0_IRQHandler() {
	int status = I2C0->IF;
	if(status & I2C_IF_ADDR) {
		i2c_rxInProgress = true;
		I2C0->RXDATA;
		I2C_IntClear(I2C0, I2C_IFC_ADDR);
	} else if(status & I2C_IF_RXDATAV) {
		i2c_rxBuffer[i2c_rxBufferIndex] = I2C0->RXDATA;
		i2c_rxBufferIndex++;
	}

	if(status & I2C_IEN_SSTOP) {
		I2C_IntClear(I2C0, I2C_IEN_SSTOP);
		i2c_rxInProgress = false;
		i2c_rxBufferIndex = 0;
	}
}
