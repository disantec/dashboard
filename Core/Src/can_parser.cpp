// can_parser.cpp

#include "can_parser.h"

can_parser *can_parser::p_instance_ = nullptr;

void can_parser::process()
{
    // Scoop up all available CAN messages that have come in and forward them off for processing.
    // This processing loop will continue so long as messages are available in the FIFO.
    #ifdef TEST_MODE
    while (p_test_mode->get_rx_message(&rxHeader, rxData))
    #else
    while (0 != HAL_CAN_GetRxFifoFillLevel(&hcan2, CAN_RX_FIFO0) &&
            HAL_OK == HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &rxHeader, rxData))
    #endif
    {   
        uint16_t data_a = (uint16_t)(rxData[1] | (rxData[0] << 8));
        uint16_t data_b = (uint16_t)(rxData[3] | (rxData[2] << 8));
        uint16_t data_c = (uint16_t)(rxData[5] | (rxData[4] << 8));
        uint16_t data_d = (uint16_t)(rxData[7] | (rxData[6] << 8));

        switch (rxHeader.StdId)
        {
            case 0x5F0:
                // RPM, Throttle Position, Ground Speed, Engine Temp
                p_data_store_->set_rpm      (data_a);
                p_data_store_->set_tps      (data_b);
                p_data_store_->set_gndspd   (data_c);
                p_data_store_->set_engtmp   (data_d);
                break;
            case 0x5F1:
                // Inlet Air Temp, Gear, Lambda 1, MAP
                //p_data_store_->set_inltmp (data_a);
                p_data_store_->set_gear     (data_b);
                p_data_store_->set_lambda   (data_c);
                //p_data_store_->set_map    (data_d);
                break;
            case 0x5F2:
                // BAP, Batt Voltage
                //p_data_store_->set_bap    (data_a);
                p_data_store_->set_batt     (data_b);
                break;
            default:
                // Do nothing.
                break;
        }    
    }
}