#include "stm32f4xx_hal.h"
#include "test_mode.h"
#include "can_parser.h"
#include "mpu_6050.h"
#include "sd_logger.h"

#define TEST_MODE // Uncomment when test mode is desired.

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Application C++ entry point. Responsible for CAN monitoring and delegation of processing.
/// 
/// @param arg  Applicable args from C invocation. Unused
/// @param hcan Pointer to the desired CAN peripheral's handler.
/// @param hi2c1 Pointer to the desired I2C peripheral's handler.

void application_main(void *arg)//, CAN_HandleTypeDef *hcan, I2C_HandleTypeDef *hi2c)
{
    CAN_RxHeaderTypeDef   rxHeader;  ///< Incoming CAN message header info.
    uint8_t               rxData[8]; ///< Incoming CAN message data bytes.

    data_store *p_data_store = data_store::instance();  ///< Pointer to data_store instance.
    can_parser *p_can_parser = can_parser::instance();  ///< Pointer to can_parser instance.
    mpu_6050   *p_mpu_6050   = mpu_6050::instance();    ///< Pointer to mpu_6050 instance.
    sd_logger  *p_sd_logger  = sd_logger::instance();   ///< Pointer to sd_logger instance.

    #ifdef TEST_MODE
    test_mode  *p_test_mode = test_mode::instance();    ///< Pointer to test_mode instance.
    #endif

    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        // For each main loop, scoop up all available CAN messages that have come in and forward them off for processing.
        // This processing loop will continue so long as messages are available in the FIFO.
        #ifdef TEST_MODE
        while (p_test_mode->get_rx_message(&rxHeader, rxData))
        #else
        while (0 != HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) && HAL_OK == HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxData))
        #endif
        {
            p_can_parser->process(rxHeader.StdId, rxData);       
        }

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

        // i2c processing
        /*if (!p_mpu_6050->init(hi2c))
        {
            p_data_store->set_rpm(65535);
        }
        p_mpu_6050->process(rxHeader.StdId, rxData);*/

        p_sd_logger->process();

        // Provide a 1ms sleep to limit the MCU from running as fast as possible. 
        HAL_Delay(1);  
    }
}

#ifdef __cplusplus
}
#endif