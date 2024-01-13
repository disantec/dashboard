#include <mpu6050.h>
#include <main.h>
#include <stdio.h>


extern I2C_HandleTypeDef hi2c1;

void mpu6050_init()

{

    {
      HAL_StatusTypeDef ret = HAL_I2C_IsDeviceReady (&hi2c1, (DEVICE_ADDRESS << 1) + 0, 1, 100);

            if(ret == HAL_OK)

                // HAL_GPIO_WritePin (GPIOG, GPIO_PIN_6, GPIO_PIN_SET);

                printf("the device is ready \n");

            else

                printf("the device is not ready check cables \n");

                // HAL_GPIO_WritePin (GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);

      uint8_t temp_data = 0b00001000;
        ret = HAL_I2C_Mem_Write (&hi2c1, (DEVICE_ADDRESS << 1) + 0 , REG_CONFIG_GYRO, 1, &temp_data, 1, 100);

            if(ret == HAL_OK)

                    // HAL_GPIO_WritePin (GPIOG, GPIO_PIN_6, GPIO_PIN_SET);

                    printf("writing to register 27 \n");

                else

                    printf("unable to write to register \n");

                    // HAL_GPIO_WritePin (GPIOG, GPIO_PIN_6, GPIO_PIN_RESET); 

    }
}