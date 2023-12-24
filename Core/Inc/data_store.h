// data_store.h

#ifndef DATASTORE_H
#define DATASTORE_H

#include <stdint.h>

class data_store 
{
public:
    static data_store *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new data_store(); }

        return p_instance_;
    }

    void set_rpm(double rpm) { rpm_ = rpm; }
    double get_rpm() { return rpm_; }

    void set_tps(double tps) { tps_ = tps; }
    double get_tps() { return tps_; }

private:
    data_store() { /* Default Constructor */ }

    static data_store *p_instance_;
    
    //#TODO: maybe make rpm_ an int
    double rpm_ = 0.0;
    double tps_ = 0.0;

    uint32_t test = 0;
};

#endif