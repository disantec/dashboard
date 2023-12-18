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

    data_store::instance()->set_rpm(1);

    while (true) 
    {
        TxHeader.StdId = 0x11;
        TxHeader.RTR = CAN_RTR_DATA;
        TxHeader.IDE = CAN_ID_STD;
        TxHeader.DLC = 2;
        TxHeader.TransmitGlobalTime = DISABLE;
        TxData[0] = 0xCA;
        TxData[1] = 0xFE;
        
        /* Request transmission */
        if(HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) != HAL_OK)
        {
            // Assume successful.
        }
        
        /* Wait transmission complete */
        while(HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3) 
        { 
            // Uncomment to confirm infinite loop. This will happen if a second node
            // is not on the bus to ACK the test message we're sending out.
            //count++; data_store::instance()->set_rpm(count);
        }

        count = 0;

        /*##-5- Start the Reception process ########################################*/
        if(HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) != 1)
        {
            /* Reception Missing */
            data_store::instance()->set_rpm(4);
        }
        else if(HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
        {
            /* Reception Error */
            data_store::instance()->set_rpm(5);
        }
        else
        {
            data_store::instance()->set_rpm(6);
        }
    }
}

#ifdef __cplusplus
}
#endif