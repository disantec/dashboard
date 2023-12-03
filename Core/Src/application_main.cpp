#include "data_store.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "main.h"


#ifdef __cplusplus
extern "C" {
#endif

void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    int rpm=1, rpmstore;

    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    
    if(HAL_OK != HAL_CAN_Start(hcan))
    {
        data_store::instance()->set_rpm(666);
    }
    else
    {
        while (true) 
        {
            
            /*while (rpmstore<10) {
                rpmstore=++rpm;

                osDelay(500);

                //data_store::instance()->set_rpm(rpmstore);
            }
            
            rpm = 1;
            rpmstore = 1;
            
            //data_store::instance()->set_rpm(rpmstore);*/

            if (HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData))
            {
                rpm = 111;
            }
            else
            {
                rpm = 222;
            }

            data_store::instance()->set_rpm(rpm);
            
            HAL_Delay(500);
        }
    }
}

#ifdef __cplusplus
}
#endif