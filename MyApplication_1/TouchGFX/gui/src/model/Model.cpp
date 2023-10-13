#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "C:\Users\disan\Documents\GIT\Dashboard\dashboard\MyApplication_1\Core\Inc\data_store.h"

#ifndef SIMULATOR
#include "main.h"


extern "C"
{

}
#endif

Model::Model() : modelListener(0), RPM_VAL(50)
{

}

void Model::tick()
{
    
    RPM_VAL = data_store::instance()->get_rpm();
    // RPM_VAL=69;

    modelListener->setRPM (RPM_VAL);
}
