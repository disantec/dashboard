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
    test_mode() { /* Intentionally empty */ }

    static test_mode *p_instance_;

    test_mode *p_test_mode_ = nullptr;
};

#endif