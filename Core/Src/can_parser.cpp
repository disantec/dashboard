// can_parser.cpp

#include "can_parser.h"

can_parser *can_parser::p_instance_ = nullptr;

void can_parser::process(uint32_t id, uint8_t data[])
{
    switch (id)
    {
        case 0x5F0:
            // RPM, Throttle Position, Ground Speed, Engine Temp
            p_data_store_->set_rpm((uint16_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_tps((uint16_t)(data[3] | (data[2] << 8)));
            p_data_store_->set_gndspd((uint16_t)(data[5] | (data[4] << 8)));
            p_data_store_->set_engtmp((uint16_t)(data[7] | (data[6] << 8)));
            break;
        case 0x5F1:
            // Inlet Air Temp, Gear, Lambda 1, MAP
            // p_data_store_->set_inltmp((uint16_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_gear((uint16_t)(data[3] | (data[2] << 8)));
            p_data_store_->set_lambda((uint16_t)(data[5] | (data[4] << 8)));
            // p_data_store_->set_map((uint16_t)(data[7] | (data[6] << 8)));
            break;
        case 0x5F2:
            // BAP, Batt Voltage
            // p_data_store_->set_bap((uint16_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_batt((uint16_t)(data[3] | (data[2] << 8)));
            break;
        default:
            // Do nothing.
            break;
    }
}