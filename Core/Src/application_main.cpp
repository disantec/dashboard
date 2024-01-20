#include "stm32f4xx_hal.h"
#include "can_parser.h"
#include "mpu_6050.h"
#include "sd_logger.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Application C++ entry point. Responsible for maintaining main loop and delegation of processing.
/// 
/// @param arg  Applicable args from C invocation. Unused

void application_main(void *arg)
{
    // Initialize all required instances.
    data_store *p_data_store = data_store::instance();  ///< Pointer to data_store instance.
    can_parser *p_can_parser = can_parser::instance();  ///< Pointer to can_parser instance.
    mpu_6050   *p_mpu_6050   = mpu_6050::instance();    ///< Pointer to mpu_6050 instance.
    sd_logger  *p_sd_logger  = sd_logger::instance();   ///< Pointer to sd_logger instance.

    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        p_can_parser->process();

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