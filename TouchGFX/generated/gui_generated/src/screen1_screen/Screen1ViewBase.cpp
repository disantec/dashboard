/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    batt.setPosition(675, 445, 107, 24);
    batt.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    batt.setLinespacing(0);
    Unicode::snprintf(battBuffer, BATT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_82MB).getText());
    batt.setWildcard(battBuffer);
    batt.setTypedText(touchgfx::TypedText(T_BATT));
    add(batt);

    engtmp.setPosition(679, 413, 92, 24);
    engtmp.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    engtmp.setLinespacing(0);
    Unicode::snprintf(engtmpBuffer, ENGTMP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_3AXW).getText());
    engtmp.setWildcard(engtmpBuffer);
    engtmp.setTypedText(touchgfx::TypedText(T_ENGTMP));
    add(engtmp);

    lambda.setPosition(675, 380, 93, 24);
    lambda.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lambda.setLinespacing(0);
    Unicode::snprintf(lambdaBuffer, LAMBDA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1CGZ).getText());
    lambda.setWildcard(lambdaBuffer);
    lambda.setTypedText(touchgfx::TypedText(T_LAMBDA1));
    add(lambda);

    tps.setPosition(679, 348, 99, 24);
    tps.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tps.setLinespacing(0);
    Unicode::snprintf(tpsBuffer, TPS_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_88RJ).getText());
    tps.setWildcard(tpsBuffer);
    tps.setTypedText(touchgfx::TypedText(T_TPS));
    add(tps);

    rpm.setPosition(243, 196, 314, 88);
    rpm.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    rpm.setLinespacing(0);
    Unicode::snprintf(rpmBuffer, RPM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZEOI).getText());
    rpm.setWildcard(rpmBuffer);
    rpm.setTypedText(touchgfx::TypedText(T_RPM));
    add(rpm);

    rpm_label.setPosition(504, 264, 107, 29);
    rpm_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    rpm_label.setLinespacing(0);
    rpm_label.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K2H6));
    add(rpm_label);

    mph_label.setPosition(243, 115, 107, 29);
    mph_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    mph_label.setLinespacing(0);
    mph_label.setTypedText(touchgfx::TypedText(T___SINGLEUSE_14NY));
    add(mph_label);

    gear_label.setPosition(558, 115, 107, 29);
    gear_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gear_label.setLinespacing(0);
    gear_label.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VPGR));
    add(gear_label);

    image1.setXY(6, 357);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ZR112_ID));
    add(image1);

    gndspd.setXY(194, 95);
    gndspd.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gndspd.setLinespacing(0);
    Unicode::snprintf(gndspdBuffer, GNDSPD_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_7ZGC).getText());
    gndspd.setWildcard(gndspdBuffer);
    gndspd.resizeToCurrentText();
    gndspd.setTypedText(touchgfx::TypedText(T_GNDSPD));
    add(gndspd);

    gear.setXY(545, 95);
    gear.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gear.setLinespacing(0);
    Unicode::snprintf(gearBuffer, GEAR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_83V3).getText());
    gear.setWildcard(gearBuffer);
    gear.resizeToCurrentText();
    gear.setTypedText(touchgfx::TypedText(T_XACCEL));
    add(gear);

    xaccel.setXY(375, 18);
    xaccel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    xaccel.setLinespacing(0);
    Unicode::snprintf(xaccelBuffer, XACCEL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_VDUL).getText());
    xaccel.setWildcard(xaccelBuffer);
    xaccel.resizeToCurrentText();
    xaccel.setTypedText(touchgfx::TypedText(T_XACCEL));
    add(xaccel);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick execute C++ code
    //Execute C++ code
    //sample code
}
