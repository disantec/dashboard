// test_mode.cpp

#include "test_mode.h"

test_mode *test_mode::p_instance_ = nullptr;

bool test_mode::get_rx_message(CAN_RxHeaderTypeDef *pHeader, uint8_t data[])
{
    if (burst_active_ && MESSAGE_BURST_COUNT > burst_count_)
    {
        pHeader->StdId = MESSAGE_LIST[burst_count_];
        populate_message(pHeader->StdId, data);
        burst_count_++;
        return true;
    }
    else if (!burst_active_ && MESSAGE_BURST_DELAY > burst_count_)
    {
        burst_count_++;
        return false;
    }
    else
    {
        burst_active_ = !burst_active_;
        burst_count_ = 0;
        return get_rx_message(pHeader, data);
    }
}

void test_mode::populate_message(uint32_t id, uint8_t data[])
{
    uint16_t data_a = 0x0000;
    uint16_t data_b = 0x0000;
    uint16_t data_c = 0x0000;
    uint16_t data_d = 0x0000;

    switch(id)
    {
        case 0x5F0:
            data_a = p_data_store_->get_rpm();
            data_b = p_data_store_->get_tps();
            data_c = p_data_store_->get_gndspd();
            data_d = p_data_store_->get_engtmp();
        break;

        case 0x5F1:
            data_a = p_data_store_->get_inltmp();
            data_b = p_data_store_->get_gear();
            data_c = p_data_store_->get_lambda();
            data_d = p_data_store_->get_map();
        break;

        case 0x5F2:
            data_a = p_data_store_->get_bap();
            data_b = p_data_store_->get_batt();
        break;

        default:
            // Do nothing.
        break;
    }

    can_data_pack(++data_a, &data[0]);
    can_data_pack(++data_b, &data[2]);
    can_data_pack(++data_c, &data[4]);
    can_data_pack(++data_d, &data[6]);
}