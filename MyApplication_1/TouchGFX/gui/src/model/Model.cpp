#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "data_store.h"

#ifndef SIMULATOR
#include "main.h"


extern "C"
{

}
#endif

//#TODO: Remove this once data_store.cpp is compiled in.
data_store *data_store::p_instance_ = nullptr;

Model::Model() : modelListener(0), RPM_VAL(50)
{

}

void Model::tick()
{
    
    RPM_VAL = data_store::instance()->get_rpm();
    // RPM_VAL=69;

    modelListener->setRPM (RPM_VAL);
}
