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

    void set_rpm(uint16_t rpm) { rpm_ = rpm; }
    uint16_t get_rpm() { return rpm_; }

    void set_tps(uint16_t tps) { tps_ = tps; }
    uint16_t get_tps() { return tps_; }

    void set_gndspd(uint16_t gndspd) { gndspd_ = gndspd; }
    uint16_t get_gndspd() { return gndspd_; }

    void set_engtmp(uint16_t engtmp) { engtmp_ = engtmp; }
    uint16_t get_engtmp() { return engtmp_; }

    void set_inltmp(uint16_t inltmp) { inltmp_ = inltmp; }
    uint16_t get_inltmp() { return inltmp_; }

    void set_gear(uint16_t gear) { gear_ = gear; }
    uint16_t get_gear() { return gear_; }

    void set_lambda(uint16_t lambda) { lambda_ = lambda; }
    uint16_t get_lambda() { return lambda_; }

    void set_map(uint16_t map) { map_ = map; }
    uint16_t get_map() { return map_; }

    void set_bap(uint16_t bap) { bap_ = bap; }
    uint16_t get_bap() { return bap_; }

    void set_batt(uint16_t batt) { batt_ = batt; }
    uint16_t get_batt() { return batt_; }

    void set_xaccel(uint32_t xaccel) { xaccel_ = xaccel; }
    uint32_t get_xaccel() { return xaccel_; }

    // void set_yaccel(uint32_t yaccel) { yaccel_ = yaccel; }
    // uint32_t get_yaccel() { return yaccel_; }
    
    // void set_zaccel(uint32_t zaccel) { zaccel_ = zaccel; }
    // uint32_t get_zaccel() { return zaccel_; }

    // void set_lat(uint32_t lat) { lat_ = lat; }
    // uint32_t get_lat() { return lat_; }

    // void set_long(uint32_t long) { long_ = long; }
    // uint32_t get_long() { return long_; }

    // void set_time(uint32_t time) { time_ = time; }
    // uint32_t get_time() { return time_; }

    void set_gps(uint32_t gps) { gps_ = gps; }
    uint32_t get_gps() { return gps_; }

private:
    static data_store *p_instance_;
    
    uint16_t rpm_       = 0;
    uint16_t tps_       = 0;
    uint16_t gndspd_    = 0;
    uint16_t engtmp_    = 0;
    uint16_t inltmp_    = 0;
    uint16_t gear_      = 0;
    uint16_t lambda_    = 0;
    uint16_t map_       = 0;
    uint16_t bap_       = 0;
    uint16_t batt_      = 0;
  

    ///@todo Determine data type
    uint32_t xaccel_    = 0;
    // uint32_t yaccel_    = 0;
    // uint32_t zaccel_    = 0;
    // uint32_t lat_       = 0;
    // uint32_t long_       = 0;
    // uint32_t time_       = 0;
    uint32_t gps_       = 0;

    data_store() { /* Default Constructor */ }
};

#endif