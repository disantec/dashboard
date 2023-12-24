#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Application C++ entry point. Responsible for CAN monitoring and delegation of processing.
///
/// @param arg  Applicable args from C invocation. Unused
/// @param hcan Pointer to the desired CAN peripheral's handler.
void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef   RxHeader;  ///< Incoming CAN message header info.
    uint8_t               RxData[8]; ///< Incoming CAN message data bytes.
    
    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        // 
        while (0 != HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) && HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData))
        {
            ///@todo Call upon processing instance.
        }

        // Provide a 1ms sleep to limit the MCU from running as fast as possible. 
        HAL_Delay(1);
    }
}

#ifdef __cplusplus
}
#endif