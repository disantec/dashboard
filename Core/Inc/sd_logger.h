// sd_logger.h

#ifndef SDLOGGER_H
#define SDLOGGER_H

#include "stm32f4xx_hal.h"
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

    sd_logger() { p_data_store_ = data_store::instance(); }
};

#endif