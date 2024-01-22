// neo6m.cpp

#include "neo6m.h"
// #include "NMEA.h"
// #include "uartRingBuffer.h"
#include "main.h"

uint8_t buffer[128] = {'\0'};

neo_6m *neo_6m::p_instance_ = nullptr;

void neo_6m::process()
{
while (1) {
 p_data_store_->set_rpm(HAL_UART_Receive_IT(&huart6, buffer, 8));
}

}