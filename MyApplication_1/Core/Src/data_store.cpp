// data_store.cpp
#include "data_store.h"

data_store::data_store() : rpm_(0.0) {}

data_store* data_store::initialize()
{
    if (nullptr == p_instance)
    {
        p_instance = new data_store();
    }
    return p_instance;
}