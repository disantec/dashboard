#include <platform/hal/simulator/sdl2/HALSDL2.hpp>
#include <touchgfx/hal/NoDMA.hpp>
#include <common/TouchGFXInit.hpp>
#include <gui_generated/common/SimConstants.hpp>
#include <platform/driver/touch/SDL2TouchController.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <stdlib.h>
#include <simulator/mainBase.hpp>
#include "data_store.h"

using namespace touchgfx;

// This line is required when running the simulator as the data_store.cpp will not
// be compiled in. Without this, p_instance_ will remain undefined and compilation will not work.
data_store *data_store::p_instance_ = nullptr;

#ifdef __linux__
int main(int argc, char** argv)
{
#else
#include <shellapi.h>
#ifdef _UNICODE
#error Cannot run in unicode mode
#endif
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int argc;
    char** argv = touchgfx::HALSDL2::getArgv(&argc);
#endif

    touchgfx::NoDMA dma; //For windows/linux, DMA transfers are simulated
    LCD& lcd = setupLCD();
    touchgfx::SDL2TouchController tc;

    touchgfx::HAL& hal = touchgfx::touchgfx_generic_init<touchgfx::HALSDL2>(dma, lcd, tc, SIM_WIDTH, SIM_HEIGHT, 0, 0);

    setupSimulator(argc, argv, hal);

    // Ensure there is a console window to print to using printf() or
    // std::cout, and read from using e.g. fgets or std::cin.
    // Alternatively, instead of using printf(), always use
    // touchgfx_printf() which will ensure there is a console to write
    // to.
    //touchgfx_enable_stdio();
    data_store::instance()->set_rpm(666);

    touchgfx::HAL::getInstance()->taskEntry(); //Never returns

    return EXIT_SUCCESS;
}
