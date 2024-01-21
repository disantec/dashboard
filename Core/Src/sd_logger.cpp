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
    if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) != FR_OK)
    {
      /* FatFs Initialization Error */
      p_data_store_->set_rpm(21000);
    }
    else
    {
        /*##-3- Create a FAT file system (format) on the logical drive #########*/
        if(f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, read_buffer, sizeof(read_buffer)) != FR_OK)
        {     
            p_data_store_->set_rpm(22000);
        }
        else
        {
            p_data_store_->set_rpm(23000);
        }
    }

    /*if (FR_OK == sd_mount())
    {
        p_data_store_->set_rpm(sd_mkfs() * 1000);
    }
    else
    {
       p_data_store_->set_rpm(sd_mkfs() * 21000);
    }*/
}

void sd_logger::handle_removal()
{
    p_data_store_->set_rpm(20000);
}