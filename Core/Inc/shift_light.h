// shift_light.h

#ifndef SHIFTLIGHT_H
#define SHIFTLIGHT_H

#include "gpio.h"

#include "data_store.h"

class shift_light 
{
public:
    static shift_light *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new shift_light(); }

        return p_instance_;
    }

    void process();

private:
    shift_light() 
    { 
        p_data_store_ = data_store::instance();
    }

    static shift_light *p_instance_;

    data_store *p_data_store_   = nullptr;    ///< Pointer to data store instance.
};

#endif