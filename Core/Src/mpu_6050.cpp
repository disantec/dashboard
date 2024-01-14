// mpu_6050.cpp

#include "mpu_6050.h"

mpu_6050 *mpu_6050::p_instance_ = nullptr;

void mpu_6050::process(uint32_t id, uint8_t data[])
{
    switch (id)
    {
        case 0x5F0:
            // RPM, Throttle Position, Ground Speed, Engine Temp
            // Endianness is probably wrong, but it's a start.
            p_data_store_->set_rpm((uint32_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_tps((uint32_t)(data[3] | (data[2] << 8)));
            p_data_store_->set_gndspd((uint32_t)(data[5] | (data[4] << 8)));
            p_data_store_->set_engtmp((uint32_t)(data[7] | (data[6] << 8)));
            break;
        case 0x5F1:
            // Inlet Air Temp, Gear, Lambda 1, MAP
            // p_data_store_->set_inltmp((uint32_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_gear((uint32_t)(data[3] | (data[2] << 8)));
            p_data_store_->set_lambda((uint32_t)(data[5] | (data[4] << 8)));
            // p_data_store_->set_map((uint32_t)(data[7] | (data[6] << 8)));
            break;
        case 0x5F2:
            // BAP, Batt Voltage
            // p_data_store_->set_bap((uint32_t)(data[1] | (data[0] << 8)));
            p_data_store_->set_batt((uint32_t)(data[3] | (data[2] << 8)));
            break;
        default:
            // Do nothing.
            break;
    }
}