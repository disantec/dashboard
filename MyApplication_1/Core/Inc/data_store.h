// data_store.h
#pragma once

class data_store {
private:
    static *p_instance=nullptr;
    
    // maybe make rpm_ an int
    double rpm_;
    double tps;
    

public:
    data_store();

    void set_rpm(double rpm) { rpm_ = rpm; }
    double get_rpm() { return rpm; }

    static data_store* initialize();
};
