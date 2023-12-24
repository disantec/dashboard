/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    tps.setPosition(679, 18, 111, 39);
    tps.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tps.setLinespacing(0);
    Unicode::snprintf(tpsBuffer, TPS_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_88RJ).getText());
    tps.setWildcard(tpsBuffer);
    tps.setTypedText(touchgfx::TypedText(T_TPS));
    add(tps);

    rpm.setPosition(300, 196, 201, 88);
    rpm.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    rpm.setLinespacing(0);
    Unicode::snprintf(rpmBuffer, RPM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZEOI).getText());
    rpm.setWildcard(rpmBuffer);
    rpm.setTypedText(touchgfx::TypedText(T_RPM));
    add(rpm);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}
