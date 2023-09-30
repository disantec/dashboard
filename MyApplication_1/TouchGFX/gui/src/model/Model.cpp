#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"

#endif

Model::Model() : modelListener(0), RPM_VAL(50)
{

}

void Model::tick()
{

    // RPM_VAL = (RPM_VAL >= 10) ? 1 : RPM_VAL + 1;
    RPM_VAL = RCC_OscInitStruct.PLL.PLLM 

    modelListener->setRPM (RPM_VAL);
}