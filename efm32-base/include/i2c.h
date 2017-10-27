#include <stdbool.h>

volatile bool i2c_rxInProgress;
volatile bool i2c_startTx;

void enable_i2c_clocks();
void enableI2CSlaveInterrupts();
void disableI2CInterrupts();
void setupI2C();
void recieveI2CData();
void performI2CTransfer();
void setupRTC();

