// can_parser.h

#ifndef CANPARSER_H
#define CANPARSER_H

#include "can.h"

#define TEST_MODE // Uncomment when test mode is desired.

#ifdef TEST_MODE
#include "test_mode.h"
#else
#include "data_store.h"
#endif

class can_parser 
{
public:
    static can_parser *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new can_parser(); }

        return p_instance_;
    }

    void process();

private:
    static can_parser *p_instance_;

    data_store *p_data_store_   = nullptr;    ///< Pointer to data store instance.

    #ifdef TEST_MODE
    test_mode  *p_test_mode     = nullptr;    ///< Pointer to test_mode instance.
    #else
    CAN_HandleTypeDef *p_can_   = nullptr;    ///< Pointer to CAN peripheral instance.
    #endif
    
    CAN_RxHeaderTypeDef   rxHeader;         ///< Incoming CAN message header info.
    uint8_t               rxData[8];        ///< Incoming CAN message data bytes.

    can_parser() 
    { 
        p_data_store_ = data_store::instance();

        #ifdef TEST_MODE
        p_test_mode = test_mode::instance();
        #else
        p_can_ = &hcan2;
        #endif
        
    }
};

#endif