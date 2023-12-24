#include "data_store.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "main.h"


#ifdef __cplusplus
extern "C" {
#endif

void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    CAN_TxHeaderTypeDef   TxHeader;
    CAN_RxHeaderTypeDef   RxHeader;
    uint8_t               TxData[8];
    uint8_t               RxData[8];
    uint32_t              TxMailbox;

    uint32_t count = 0;

    data_store::instance()->set_rpm(88);

    while (true) 
    {
        if (0 != HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) && HAL_OK==HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData))
        {
            count++;

        }

        data_store::instance()->set_rpm(count);





    }
}

#ifdef __cplusplus
}
#endif