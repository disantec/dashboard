// mpu_6050.h

#ifndef MPU6050_H_
#define MPU6050_H_

#include "i2c.h"

#include "data_store.h"

#define DEVICE_ADDRESS 0x68

#define FS_GYRO_250  0
#define FS_GYRO_500  8
#define FS_GYRO_1000 9
#define FS_GYRO_2000 10

#define FS_ACC_2G  0
#define FS_ACC_4G  8
#define FS_ACC_8G  9
#define FS_ACC_16G 10

#define REG_CONFIG_GYRO  27
#define REG_CONFIG_ACC   28
#define REG_USR_CTRL     107
#define REG_DATA         59

class mpu_6050
{
public:
    static mpu_6050 *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new mpu_6050(); }

        return p_instance_;
    }

    void process();

private:
    mpu_6050() 
    { 
        p_data_store_ = data_store::instance();

       ///@todo Find a way to communicate with the imu.
       if (HAL_OK == HAL_I2C_IsDeviceReady (&hi2c1, (DEVICE_ADDRESS << 1) + 0, 1, 100))
       {
            //uint8_t temp_data = 0b00001000;
            //if (HAL_OK == HAL_I2C_Mem_Write (hi2c, (DEVICE_ADDRESS << 1) + 0 , REG_CONFIG_GYRO, 1, &temp_data, 1, 100))
            //{
                p_i2c_ = &hi2c1;
            //}
       }
    }

    static mpu_6050 *p_instance_;

    data_store *p_data_store_ = nullptr;

    I2C_HandleTypeDef *p_i2c_ = nullptr;
};

#endif

