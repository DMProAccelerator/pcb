#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_rtc.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

#define CORE_FREQUENCY		14000000
#define RTC_MIN_TIMEOUT		32000
#define I2C_ADDRESS		0xE2
#define I2C_RXBUFFER_SIZE	10

uint8_t	i2c_txBuffer[]	= "Gecko";
uint8_t	i2c_txBufferSize= sizeof(i2c_txBuffer);
uint8_t i2c_rxBuffer[I2C_RXBUFFER_SIZE];
uint8_t	i2c_rxBufferIndex;

volatile bool i2c_rxInProgress;
volatile bool i2c_startTx;

void setupOscillators(void) {
  CMU_ClockEnable(cmuClock_I2C0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_CORELE, true);

  CMU_ClockEnable(cmuClock_USART0, true);

  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_RTC, true);
}

void enableI2cSlaveInterrupts(void) {
  I2C_IntClear(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
  I2C_IntEnable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
  NVIC_EnableIRQ(I2C0_IRQn);
}

void disableI2cInterrupts(void){
  NVIC_DisableIRQ(I2C0_IRQn);
  I2C_IntDisable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
  I2C_IntClear(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
}

void setupI2C(void) {
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;

  /* Using PD6 (SDA) and PD7 (SCL) */
  GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndPullUpFilter, 1);
  
  // Setting up PC0 to indicate transfer direction
  GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 0);

  /* Enable pins at location 1 */
  I2C0->ROUTE = I2C_ROUTE_SDAPEN |
                I2C_ROUTE_SCLPEN |
                (1 << _I2C_ROUTE_LOCATION_SHIFT);

  /* Initializing the I2C */
  I2C_Init(I2C0, &i2cInit);
  
  /* Setting the status flags and index */
  i2c_rxInProgress = false;
  i2c_startTx = false;
  i2c_rxBufferIndex = 0;

  /* Setting up to enable slave mode */
  I2C0->SADDR = I2C_ADDRESS;
  I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN;
  enableI2cSlaveInterrupts(); 
}



/**************************************************************************//**
 * @brief  Receiving I2C data. Along with the I2C interrupt, it will keep the 
  EFM32 in EM1 while the data is received.
 *****************************************************************************/
void receiveI2CData(void) {
  while(i2c_rxInProgress) {
    EMU_EnterEM1();
  }
}



/**************************************************************************//**
 * @brief  Transmitting I2C data. Will busy-wait until the transfer is complete.
 *****************************************************************************/
void performI2CTransfer(void)
{
  /* Transfer structure */
  I2C_TransferSeq_TypeDef i2cTransfer;
  
  /* Setting pin to indicate transfer */
  GPIO_PinOutSet(gpioPortC, 0);
  
  /* Initializing I2C transfer */
  i2cTransfer.addr          = I2C_ADDRESS;
  i2cTransfer.flags         = I2C_FLAG_WRITE;
  i2cTransfer.buf[0].data   = i2c_txBuffer;
  i2cTransfer.buf[0].len    = i2c_txBufferSize;
  i2cTransfer.buf[1].data   = i2c_rxBuffer;
  i2cTransfer.buf[1].len    = I2C_RXBUFFER_SIZE;   
  I2C_TransferInit(I2C0, &i2cTransfer);
  
  /* Sending data */ 
  while (I2C_Transfer(I2C0) == i2cTransferInProgress){;}  
  
  /* Clearing pin to indicate end of transfer */
  GPIO_PinOutClear(gpioPortC, 0);      
  enableI2cSlaveInterrupts();  
}



/**************************************************************************//**
 * @brief  Setup RTC
 *****************************************************************************/
void setupRTC(void)
{  
  /* Variable for calculating the RTC timeout */
  uint16_t rtcTimeout;    
  RTC_Init_TypeDef rtcInit = RTC_INIT_DEFAULT;
  
  /* Getting an individual timeout value based upon the UNIQUE_0 field in the
  Device Information table */
  rtcTimeout = (*(uint32_t*)0x0FE081F0);  
  /* Setting a minimum timeout value */
  if(rtcTimeout < RTC_MIN_TIMEOUT){
    rtcTimeout += RTC_MIN_TIMEOUT;
  }
 
  // Setting RTC timeout
  RTC_CompareSet(0, rtcTimeout);

  /* Enabling Interrupt from RTC */
  RTC_IntEnable(RTC_IFC_COMP0);
  NVIC_EnableIRQ(RTC_IRQn);

  /* Enabling the RTC, using  */
  RTC_Init(&rtcInit);
}



/**************************************************************************//**
 * @brief  Main function
 * Main is called from __iar_program_start, see assembly startup file
 *****************************************************************************/
int main(void) {
  /* Initialize chip */
  CHIP_Init();
  
  /* Configuring clocks in the Clock Management Unit (CMU) */
  setupOscillators();
  
  /* Setting up i2c */
  setupI2C();
  
  /* Setting up rtc*/
  setupRTC();
  

  while (1) {
    if(i2c_rxInProgress){
       /* Receiving data */
       receiveI2CData();
    }else if (i2c_startTx){
       /* Transmitting data */
       performI2CTransfer();
       /* Transmission complete */
       i2c_startTx = false;       
    }
    
    /* Forever enter EM2. The RTC or I2C will wake up the EFM32 */
    EMU_EnterEM2(false);    
  }
}



/**************************************************************************//**
 * @brief RTC Interrupt Handler, clears the flag.
 *        The interrupt table is in assembly startup file startup_efm32.s
 *****************************************************************************/
void RTC_IRQHandler(void) {
  /* Clear interrupt source */
  RTC_IntClear(RTC_IFC_COMP0);
  /* If RX is not in progress, a new transfer is started*/
  if (!i2c_rxInProgress){
    disableI2cInterrupts();
    i2c_startTx = true;
  }
}


/**************************************************************************//**
 * @brief I2C Interrupt Handler.
 *        The interrupt table is in assembly startup file startup_efm32.s
 *****************************************************************************/
void I2C0_IRQHandler(void)
{
  int status;
   
  status = I2C0->IF;

  if (status & I2C_IF_ADDR){
    /* Address Match */ 
    /* Indicating that reception is started */
    i2c_rxInProgress = true;
    I2C0->RXDATA;

    I2C_IntClear(I2C0, I2C_IFC_ADDR);

  } else if (status & I2C_IF_RXDATAV){
    /* Data received */
    i2c_rxBuffer[i2c_rxBufferIndex] = I2C0->RXDATA;    
    i2c_rxBufferIndex++;
  }
  
  if(status & I2C_IEN_SSTOP){
    /* Stop received, reception is ended */
    I2C_IntClear(I2C0, I2C_IEN_SSTOP);
    i2c_rxInProgress = false;
    i2c_rxBufferIndex = 0;
  }
}
