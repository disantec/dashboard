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

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextAreaWithOneWildcard tps;
    touchgfx::TextAreaWithOneWildcard rpm;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TPS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tpsBuffer[TPS_SIZE];
    static const uint16_t RPM_SIZE = 10;
    touchgfx::Unicode::UnicodeChar rpmBuffer[RPM_SIZE];

private:

};

#endif // SCREEN1VIEWBASE_HPP
