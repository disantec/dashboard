// sd_logger.h

#ifndef SDLOGGER_H
#define SDLOGGER_H

#include "ff.h"
#include "fatfs.h"
#include "bsp_driver_sd.h"

#include "data_store.h"

class sd_logger
{
public:
    static sd_logger *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new sd_logger(); }

        return p_instance_;
    }

    void process();

private:
    static sd_logger *p_instance_;

    data_store *p_data_store_ = nullptr;

    FATFS *p_sd_fs_     = nullptr;
    char  *p_sd_path_   = nullptr;

    bool sd_detected_ = false;

    uint8_t read_buffer[_MAX_SS];

    sd_logger() 
    { 
        p_data_store_ = data_store::instance();

        p_sd_fs_    = &SDFatFS;
        p_sd_path_  = SDPath;

        // Initialize detection state.
        detect_insertion_change();
    }

    bool detect_insertion_change();
    void handle_insertion();
    void handle_removal();

    FRESULT sd_mount() { return f_mount(p_sd_fs_, p_sd_path_, 0); }
    FRESULT sd_mkfs()  { return f_mkfs(p_sd_path_, FM_FAT32, 0, read_buffer, sizeof(read_buffer)); } 
};

#endif