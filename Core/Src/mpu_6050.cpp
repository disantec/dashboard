// mpu_6050.cpp

#include "mpu_6050.h"

mpu_6050 *mpu_6050::p_instance_ = nullptr;

bool mpu_6050::init(I2C_HandleTypeDef *hi2c)
{
    if (HAL_OK == HAL_I2C_IsDeviceReady (hi2c, (DEVICE_ADDRESS << 1) + 0, 1, 100))
    {
        //uint8_t temp_data = 0b00001000;
        //if (HAL_OK == HAL_I2C_Mem_Write (hi2c, (DEVICE_ADDRESS << 1) + 0 , REG_CONFIG_GYRO, 1, &temp_data, 1, 100))
        //{
            return true;
        //}
    }

    return false;
}

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