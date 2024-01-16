// test_mode.h

#ifndef TEST_MODE_H
#define TEST_MODE_H

#include <stdint.h>

#include "stm32f4xx_hal.h"
#include "data_store.h"

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
        p_data_store_ = data_store::instance();

        burst_active_ = true;
        burst_count_ = 0;
    }

    void populate_message(CAN_RxHeaderTypeDef *pHeader, uint8_t data[]);

    void data_store_pack(uint32_t store_data, uint8_t *p_data);

    static test_mode *p_instance_;

    test_mode *p_test_mode_ = nullptr;

    data_store *p_data_store_ = nullptr;

    bool burst_active_;

    uint8_t burst_count_;
};

#endif