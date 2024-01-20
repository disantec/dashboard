// sd_logging.cpp

#include "sd_logger.h"

#include "bsp_driver_sd.h"

sd_logger *sd_logger::p_instance_ = nullptr;

void sd_logger::process()
{
    ///# Hijacks RPM to test sd card presence. NOT SUITABLE FOR ACTUAL USE.
    //p_data_store_->set_rpm(BSP_SD_IsDetected());
}