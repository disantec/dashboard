#include "stm32f4xx_hal.h"
#include "can_parser.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Application C++ entry point. Responsible for CAN monitoring and delegation of processing.
///
/// @param arg  Applicable args from C invocation. Unused
/// @param hcan Pointer to the desired CAN peripheral's handler.
void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    can_parser *p_can_parser = can_parser::instance(); ///< Pointer to the instance of can_parser.

    CAN_RxHeaderTypeDef   rxHeader;  ///< Incoming CAN message header info.
    uint8_t               rxData[8]; ///< Incoming CAN message data bytes.

    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        // For each main loop, scoop up all available CAN messages that have come in and forward them off for processing.
        // This processing loop will continue so long as messages are available in the FIFO.
        while (0 != HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) && HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxData))
        {
            p_can_parser->process(rxHeader.StdId);
        }

        // Provide a 1ms sleep to limit the MCU from running as fast as possible. 
        HAL_Delay(1);
    }
}

#ifdef __cplusplus
}
#endif