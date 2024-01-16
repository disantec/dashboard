// mpu_6050.h

#ifndef MPU6050_H_
#define MPU6050_H_

#include "stm32f4xx_hal.h"
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

    bool init(I2C_HandleTypeDef *hi2c);

    void process(uint32_t id, uint8_t data[]);

private:
    mpu_6050() { p_data_store_ = data_store::instance(); }

    static mpu_6050 *p_instance_;

    data_store *p_data_store_ = nullptr;
};

#endif

