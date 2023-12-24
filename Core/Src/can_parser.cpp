// can_parser.cpp

#include "can_parser.h"

can_parser *can_parser::p_instance_ = nullptr;

void can_parser::process(uint32_t id, uint8_t data[])
{
    switch (id)
    {
        case 0x5F0:
            // RPM, Throttle Position, Ground Speed, Engine Temp
            // Endianness is probably wrong, but it's a start.
            p_data_store_->set_rpm((uint32_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_tps((uint32_t)(data[3] | (data[2] << 8)));
            break;
        case 0x5F1:
            // Inlet Air Temp, Gear, Lambda 1, MAP
            break;
        case 0x5F2:
            // BAP, Batt Voltage
            break;
        default:
            // Do nothing.
            break;
    }
}