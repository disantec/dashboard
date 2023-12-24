#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "data_store.h"

#ifndef SIMULATOR

extern "C"
{

}
#endif

Model::Model() : modelListener(0) { /* Default constructor */ }

void Model::tick()
{
    modelListener->setRPM (data_store::instance()->get_rpm());
}
