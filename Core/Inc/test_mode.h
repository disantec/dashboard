// test_mode.h

#ifndef TEST_MODE_H
#define TEST_MODE_H

#include "stm32f4xx_hal.h"

class test_mode 
{
public:
    static test_mode *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new test_mode(); }

        return p_instance_;
    }

    bool get_rx_message(CAN_RxHeaderTypeDef *pHeader, uint8_t data[]);

private:
    uint8_t MESSAGE_BURST_COUNT = 2;
    uint8_t MESSAGE_BURST_DELAY = 1;

    test_mode() 
    {
        burst_active_ = true;
        burst_count_ = 0;
    }

    static test_mode *p_instance_;

    test_mode *p_test_mode_ = nullptr;

    bool burst_active_;

    uint8_t burst_count_;
};

#endif