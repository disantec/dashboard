// mpu_6050.cpp

#include "mpu_6050.h"

mpu_6050 *mpu_6050::p_instance_ = nullptr;

void mpu_6050::process(uint32_t id, uint8_t data[])
{
    switch (id)
    {
            p_data_store_->set_xaccel((uint32_t)(32));

        default:
            // Do nothing.
            break;
    }
}