#include "stm32f4xx_hal.h"
#include "can_parser.h"
#include "test_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

// #define TEST_MODE

/// @brief Application C++ entry point. Responsible for CAN monitoring and delegation of processing.
///
/// @param arg  Applicable args from C invocation. Unused
/// @param hcan Pointer to the desired CAN peripheral's handler.
void application_main(void *arg, CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef   rxHeader;  ///< Incoming CAN message header info.
    uint8_t               rxData[8]; ///< Incoming CAN message data bytes.

    data_store *p_data_store = data_store::instance();  ///< Pointer to data_store instance.
    can_parser *p_can_parser = can_parser::instance();  ///< Pointer to can_parser instance.
    test_mode  *p_test_mode = test_mode::instance();    ///< Pointer to test_mode instance..

    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        #ifdef TEST_MODE
        rxData[0] = 0x02;
        rxData[1] = 0x01;
        rxData[2] = 0x09;
        rxData[3] = 0x08;

        p_can_parser->process(0x5F0, rxData);
        #else
        // For each main loop, scoop up all available CAN messages that have come in and forward them off for processing.
        // This processing loop will continue so long as messages are available in the FIFO.
        while (0 != HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) && HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxData))
        {
            p_can_parser->process(rxHeader.StdId, rxData);       
        }
        #endif

        // Shift light functionality evaluated each loop. Cache the rpm from the data store prior to processing.
        uint32_t rpm = p_data_store->get_rpm();

        //  When RPM is greater than 8000, turn on the blue light
        HAL_GPIO_WritePin (GPIOG, GPIO_PIN_13, 8000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

        //  When RPM is greater than 11000, turn on the other blue light
        HAL_GPIO_WritePin (GPIOG, GPIO_PIN_11, 11000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

        //  When RPM is greater than 13000, turn on the yellow light
        HAL_GPIO_WritePin (GPIOG, GPIO_PIN_10, 13000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

        //  When RPM is greater than 14000, turn on the orange light
        HAL_GPIO_WritePin (GPIOG, GPIO_PIN_1, 14000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

        // Provide a 1ms sleep to limit the MCU from running as fast as possible. 
        HAL_Delay(1);
    }
}

#ifdef __cplusplus
}
#endif