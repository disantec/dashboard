// sd_logging.cpp

#include "ff.h"

#include "sd_logger.h"

sd_logger *sd_logger::p_instance_ = nullptr;

void sd_logger::process()
{
    if (!detect_insertion_change() && sd_detected_)
    {
        // Card has maintained insertion and may be processed for writing.
        //p_data_store_->set_rpm(2000);
    }
}

bool sd_logger::detect_insertion_change()
{
    bool insertion_change = false;

    if (BSP_SD_IsDetected() != sd_detected_) 
    {
        insertion_change = true;
        sd_detected_ = !sd_detected_;

        if (sd_detected_) { handle_insertion(); }
        else              { handle_removal(); }
    }

    return insertion_change;
}

void sd_logger::handle_insertion()
{
    uint16_t result = 0;

    if (FR_OK == sd_mount())
    {
        result = sd_mkfs() * 1000;
    }
    else
    {
        result = 21000;
    }

    p_data_store_->set_rpm(result);
}

void sd_logger::handle_removal()
{
    p_data_store_->set_rpm(20000);
}