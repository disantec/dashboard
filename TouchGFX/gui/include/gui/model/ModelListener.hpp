#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void setRPM (int val) {};
    virtual void setTPS (int val) {};
    virtual void setGNDSPD (int val) {};
    virtual void setENGTMP (int val) {};
    virtual void setGEAR (int val) {};
    virtual void setLAMBDA (int val) {};
    virtual void setBATT (int val) {};
    virtual void setXACCEL (int val) {};
    virtual void setGPS (int val) {};
    
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
