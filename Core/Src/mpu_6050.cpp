// mpu_6050.cpp

#include "mpu_6050.h"

mpu_6050 *mpu_6050::p_instance_ = nullptr;

void mpu_6050::process()
{
    ///@todo Expand to actually take readings once possible.
    p_data_store_->set_xaccel(nullptr == p_i2c_ ? 1 : 2);
}