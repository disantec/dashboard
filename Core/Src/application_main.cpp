#include "can_parser.h"
#include "shift_light.h"
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
    // Gather all required instance pointers.
    can_parser  *p_can_parser = can_parser::instance();   ///< Pointer to can_parser instance.
    shift_light *p_shift_light = shift_light::instance(); ///< Pointer to shift_light instance.
    mpu_6050    *p_mpu_6050   = mpu_6050::instance();     ///< Pointer to mpu_6050 instance.
    sd_logger   *p_sd_logger  = sd_logger::instance();    ///< Pointer to sd_logger instance.

    // Begin infinite "main" loop of program. Execution is not intended to move beyond this.
    while (true) 
    {
        p_can_parser->process();
        p_shift_light->process();
        p_mpu_6050->process();
        p_sd_logger->process();

        // Provide a 1ms sleep to limit the MCU from running as fast as possible. 
        HAL_Delay(1);  
    }
}

#ifdef __cplusplus
}
#endif