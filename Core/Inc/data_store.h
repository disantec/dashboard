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

    void set_rpm(uint32_t rpm) { rpm_ = rpm; }
    uint32_t get_rpm() { return rpm_; }

    void set_tps(uint32_t tps) { tps_ = tps; }
    uint32_t get_tps() { return tps_; }

    void set_gndspd(uint32_t gndspd) { gndspd_ = gndspd; }
    uint32_t get_gndspd() { return gndspd_; }

    void set_engtmp(uint32_t engtmp) { engtmp_ = engtmp; }
    uint32_t get_engtmp() { return engtmp_; }

    void set_inltmp(uint32_t inltmp) { inltmp_ = inltmp; }
    uint32_t get_inltmp() { return inltmp_; }

    void set_gear(uint32_t gear) { gear_ = gear; }
    uint32_t get_gear() { return gear_; }

    void set_lambda(uint32_t lambda) { lambda_ = lambda; }
    uint32_t get_lambda() { return lambda_; }

    void set_map(uint32_t map) { map_ = map; }
    uint32_t get_map() { return map_; }

    void set_bap(uint32_t bap) { bap_ = bap; }
    uint32_t get_bap() { return bap_; }

    void set_batt(uint32_t batt) { batt_ = batt; }
    uint32_t get_batt() { return batt_; }

    void set_xaccel(uint32_t xaccel) { xaccel_ = xaccel; }
    uint32_t get_xaccel() { return set_xaccel; }

    void set_yaccel(uint32_t yaccel) { yaccel_ = yaccel; }
    uint32_t get_yaccel() { return set_yaccel; }
    
    void set_zaccel(uint32_t zaccel) { zaccel_ = zaccel; }
    uint32_t get_zaccel() { return set_zaccel; }

private:
    data_store() { /* Default Constructor */ }

    static data_store *p_instance_;
    
    //#TODO: maybe make rpm_ an int
    uint32_t rpm_ = 0;
    uint32_t tps_ = 0.0;
    uint32_t gndspd_ = 0.0;
    uint32_t engtmp_ = 0.0;
    uint32_t inltmp_ = 0.0;
    uint32_t gear_ = 1;
    uint32_t lambda_ = 0.0;
    uint32_t map_ = 0.0;
    uint32_t bap_ = 0.0;
    uint32_t batt_ = 0.0;
    uint32_t xaccel_ = 0.0;
    uint32_t yaccel_ = 0.0;
    uint32_t zaccel_ = 0.0;
    


    uint32_t test = 0;
};

#endif