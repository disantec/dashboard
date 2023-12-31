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

void Screen1View::setGNDSPD (int val)
{
	Unicode::snprintf(gndspdBuffer, GNDSPD_SIZE, "%d", val);
	gndspd.invalidate();
}

void Screen1View::setENGTMP (int val)
{
	Unicode::snprintf(engtmpBuffer, ENGTMP_SIZE, "%d", val);
	engtmp.invalidate();
}

void Screen1View::setGEAR (int val)
{
	Unicode::snprintf(gearBuffer, GEAR_SIZE, "%d", val);
	gear.invalidate();
}

void Screen1View::setLAMBDA (int val)
{
	Unicode::snprintf(lambdaBuffer, LAMBDA_SIZE, "%d", val);
	lambda.invalidate();
}

void Screen1View::setBATT (int val)
{
	Unicode::snprintf(battBuffer, BATT_SIZE, "%d", val);
	batt.invalidate();
}