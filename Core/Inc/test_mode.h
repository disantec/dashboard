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
    static const uint8_t MESSAGE_BURST_COUNT = 3;
    static const uint8_t MESSAGE_BURST_DELAY = 1;

    const uint32_t MESSAGE_LIST[MESSAGE_BURST_COUNT] = {0x5F0, 0x5F1, 0x5F2};

    static test_mode *p_instance_;
    
    data_store *p_data_store_ = nullptr;

    bool burst_active_;
    uint8_t burst_count_;

    test_mode() 
    {
        p_data_store_ = data_store::instance();

        burst_active_ = true;
        burst_count_ = 0;
    }

    void can_data_pack(uint16_t store_data, uint8_t *p_data)
    {
        *p_data     = store_data >> 8;
        *(++p_data) = store_data;
    }

    void populate_message(uint32_t id, uint8_t data[]);
};

#endif