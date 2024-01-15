#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::setRPM (int val)
{
	view.setRPM (val);

}

void Screen1Presenter::setTPS (int val)
{
	view.setTPS (val * .1);

}

void Screen1Presenter::setGNDSPD (int val)
{
	view.setGNDSPD (val * .1);

}

void Screen1Presenter::setENGTMP (int val)
{
	view.setENGTMP (val * .1);

}

void Screen1Presenter::setGEAR (int val)
{
	view.setGEAR (val * .1);

}

void Screen1Presenter::setLAMBDA(int val)
{
	view.setLAMBDA (val * .001);

}

void Screen1Presenter::setBATT(int val)
{
	view.setBATT (val * .01);

}

void Screen1Presenter::setXACCEL(int val)
{
	view.setXACCEL (val * .01);

}
