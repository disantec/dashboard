#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

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

    int rpm = data_store.get_rpm();

    return 0;

    // RPM_VAL = 69;
    modelListener->setRPM (rpm);
}
