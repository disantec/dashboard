#include "data_store.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "main.h"


#ifdef __cplusplus
extern "C" {
#endif

void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    int rpm=0;

    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    CAN_TxHeaderTypeDef TxHeader;
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.StdId = 0x446;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.DLC = 2;

    uint8_t TxData[8];
    TxData[0] = 50;  
    TxData[1] = 0xAA;

    uint32_t TxMailbox;

    
    if(HAL_OK != HAL_CAN_Start(hcan))
    {
        data_store::instance()->set_rpm(666);
    }
    else
    {
        while (true) 
        {
            /*
            if (HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData))
            {
                rpm = 111;
            }
            else
            {
                rpm = 222;
            }*/

            if (HAL_OK != HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox))
            {
                rpm = 696;
            }
            else
            {
                HAL_Delay(500);

                rpm += HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) + HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO1);
            }

            data_store::instance()->set_rpm(rpm);
            
            HAL_Delay(500);
        }
    }
}

#ifdef __cplusplus
}
#endif