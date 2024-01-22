// neo_6m.h

#ifndef NEO6M_H_
#define NEO6M_H_

#include "data_store.h"
#include "usart.h"

class neo_6m
{
public:
    static neo_6m *instance()
    {
        if (nullptr == p_instance_) { p_instance_ = new neo_6m(); }

        return p_instance_;
    }

    void process();

private:
    static neo_6m *p_instance_;

    data_store *p_data_store_ = nullptr;

    UART_HandleTypeDef *p_uart_   = nullptr; 

    neo_6m() 
    { 
        p_data_store_ = data_store::instance();

        p_uart_ = &huart6;

       }
    };

#endif

