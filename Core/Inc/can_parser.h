// can_parser.h

#ifndef CANPARSER_H
#define CANPARSER_H

#include "data_store.h"

class can_parser 
{
public:
    static can_parser *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new can_parser(); }

        return p_instance_;
    }

    void process(uint32_t id, uint8_t data[]);

private:
    can_parser() { p_data_store_ = data_store::instance(); }

    static can_parser *p_instance_;

    data_store *p_data_store_ = nullptr;
};

#endif