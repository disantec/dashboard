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

    void set_gndspd(double gndspd) { gndspd_ = gndspd; }
    double get_gndspd() { return gndspd_; }

    void set_engtmp(double engtmp) { engtmp_ = engtmp; }
    double get_engtmp() { return engtmp_; }

    void set_inltmp(double inltmp) { inltmp_ = inltmp; }
    double get_inltmp() { return inltmp_; }

    void set_gear(double gear) { gear_ = gear; }
    double get_gear() { return gear_; }

    void set_lambda1(double lambda1) { lambda1_ = lambda1; }
    double get_lambda1() { return lambda1_; }

    void set_map(double map) { map_ = map; }
    double get_map() { return map_; }

    void set_bap(double bap) { bap_ = bap; }
    double get_bap() { return bap_; }

    void set_batt(double batt) { batt_ = batt; }
    double get_batt() { return batt_; }

private:
    data_store() { /* Default Constructor */ }

    static data_store *p_instance_;
    
    //#TODO: maybe make rpm_ an int
    double rpm_ = 0.0;
    double tps_ = 0.0;
    double gndspd_ = 0.0;
    double engtmp_ = 0.0;
    double inltmp_ = 0.0;
    int gear_ = 1;
    double lambda1_ = 0.0;
    double map_ = 0.0;
    double bap_ = 0.0;
    double batt_ = 0.0;
    


    uint32_t test = 0;
};

#endif