// shift_light.cpp

#include "shift_light.h"

shift_light *shift_light::p_instance_ = nullptr;

///@todo Refactor.
void shift_light::process()
{
    // Shift light functionality evaluated each loop. Cache the rpm from the data store prior to processing.
    uint16_t rpm = p_data_store_->get_rpm();

    //  When RPM is greater than 8000, turn on the blue light
    HAL_GPIO_WritePin (GPIOG, GPIO_PIN_13, 8000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

    //  When RPM is greater than 11000, turn on the other blue light
    HAL_GPIO_WritePin (GPIOG, GPIO_PIN_11, 11000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

    //  When RPM is greater than 13000, turn on the yellow light
    HAL_GPIO_WritePin (GPIOG, GPIO_PIN_10, 13000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);

    //  When RPM is greater than 14000, turn on the orange light
    HAL_GPIO_WritePin (GPIOG, GPIO_PIN_1, 14000 <= rpm ? GPIO_PIN_SET : GPIO_PIN_RESET);
}