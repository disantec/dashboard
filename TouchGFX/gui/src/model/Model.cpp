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
    modelListener->setTPS (data_store::instance()->get_tps());
    modelListener->setGNDSPD (data_store::instance()->get_gndspd());
    modelListener->setENGTMP (data_store::instance()->get_engtmp());
    modelListener->setGEAR (data_store::instance()->get_gear());
    modelListener->setLAMBDA (data_store::instance()->get_lambda());
    modelListener->setBATT (data_store::instance()->get_batt());
}
