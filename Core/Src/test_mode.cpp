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
            populate_message(pHeader, data);
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

void test_mode::populate_message(CAN_RxHeaderTypeDef *pHeader, uint8_t data[])
{
    pHeader->StdId = 0x5F0;

    data_store_pack(p_data_store_->get_rpm() + 1, &data[0]);


    /*uint32_t temp = p_data_store_->get_rpm();
    data[0] = temp >> 8;
    data[1] = temp;

    temp = p_data_store_->get_tps();
    data[2] = temp >> 8;
    data[3] = temp;

    temp = p_data_store_->get_gndspd();
    data[4] = temp >> 8;
    data[5] = temp;

    temp = p_data_store_->get_engtmp();
    data[6] = temp >> 8;
    data[7] = temp;
    */
}

void test_mode::data_store_pack(uint32_t store_data, uint8_t *p_data)
{

}