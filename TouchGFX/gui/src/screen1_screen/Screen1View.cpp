#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setRPM (int val)
{
	Unicode::snprintf(rpmBuffer, RPM_SIZE, "%d", val);
	rpm.invalidate();
}

void Screen1View::setTPS (int val)
{
	Unicode::snprintf(tpsBuffer, TPS_SIZE, "%d", val);
	tps.invalidate();
}
