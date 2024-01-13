// test_mode.cpp

#include "test_mode.h"

test_mode *test_mode::p_instance_ = nullptr;

bool test_mode::get_rx_message(CAN_RxHeaderTypeDef *pHeader, uint8_t data[])
{
    ///@todo Clean this up, time permitting.
    if (burst_active_)
    {
        if (MESSAGE_BURST_COUNT > burst_count_)
        {
            pHeader->StdId = 0x5F0;
            data[0] = 0x12;
            data[1] = 0x34;
            burst_count_++;
            return true;
        }
        else
        {
            burst_active_ = false;
            burst_count_ = 0;
            return get_rx_message(pHeader, data);
        }
    }
    else
    {
        if (MESSAGE_BURST_DELAY > burst_count_)
        {
            return false;
            burst_count_++;
        }
        else
        {
            burst_active_ = true;
            burst_count_ = 0;
            return get_rx_message(pHeader, data);
        }
    }
}