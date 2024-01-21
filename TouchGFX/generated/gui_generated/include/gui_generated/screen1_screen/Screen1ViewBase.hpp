/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
    virtual void setupScreen();
    virtual void handleTickEvent();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextAreaWithOneWildcard batt;
    touchgfx::TextAreaWithOneWildcard engtmp;
    touchgfx::TextAreaWithOneWildcard lambda;
    touchgfx::TextAreaWithOneWildcard tps;
    touchgfx::TextAreaWithOneWildcard rpm;
    touchgfx::TextArea rpm_label;
    touchgfx::TextArea mph_label;
    touchgfx::TextArea gear_label;
    touchgfx::Image image1;
    touchgfx::TextAreaWithOneWildcard gndspd;
    touchgfx::TextAreaWithOneWildcard gear;
    touchgfx::TextAreaWithOneWildcard xaccel;

    /*
     * Wildcard Buffers
     */
    static const uint16_t BATT_SIZE = 5;
    touchgfx::Unicode::UnicodeChar battBuffer[BATT_SIZE];
    static const uint16_t ENGTMP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar engtmpBuffer[ENGTMP_SIZE];
    static const uint16_t LAMBDA_SIZE = 5;
    touchgfx::Unicode::UnicodeChar lambdaBuffer[LAMBDA_SIZE];
    static const uint16_t TPS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tpsBuffer[TPS_SIZE];
    static const uint16_t RPM_SIZE = 5;
    touchgfx::Unicode::UnicodeChar rpmBuffer[RPM_SIZE];
    static const uint16_t GNDSPD_SIZE = 10;
    touchgfx::Unicode::UnicodeChar gndspdBuffer[GNDSPD_SIZE];
    static const uint16_t GEAR_SIZE = 10;
    touchgfx::Unicode::UnicodeChar gearBuffer[GEAR_SIZE];
    static const uint16_t XACCEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar xaccelBuffer[XACCEL_SIZE];

private:

};

#endif // SCREEN1VIEWBASE_HPP
