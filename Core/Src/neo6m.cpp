// neo6m.cpp

#include "neo6m.h"
// #include "NMEA.h"
// #include "uartRingBuffer.h"
#include "main.h"

uint8_t buffer[128] = {'\0'};

neo_6m *neo_6m::p_instance_ = nullptr;

void neo_6m::process()
{

 p_data_store_->set_gps(HAL_UART_Receive(&huart6, buffer, 8, 100));

}