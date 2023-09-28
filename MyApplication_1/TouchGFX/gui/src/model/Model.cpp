#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"

extern "C"
{

}
#endif

Model::Model() : modelListener(0), ADC_VAL(50)
{

}

void Model::tick()
{
#ifndef SIMULATOR

	ADC_VAL = 50;

#endif

	modelListener->setADC (ADC_VAL);
}
