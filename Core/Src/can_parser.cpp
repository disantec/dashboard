// can_parser.cpp

#include "can_parser.h"

can_parser *can_parser::p_instance_ = nullptr;

can_parser()
{
    p_data_store_ = data_store::instance();
}

void can_parser::process(uint32_t id, uint8_t data[])
{
    ///@todo Do the CAN processing.
}