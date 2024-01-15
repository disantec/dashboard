#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setRPM (int val);
    virtual void setTPS (int val);
    virtual void setGNDSPD (int val);
    virtual void setENGTMP (int val);
    virtual void setGEAR (int val);
    virtual void setLAMBDA (int val);
    virtual void setBATT (int val);
    virtual void setXACCEL (int val);

protected:
};

#endif // SCREEN1VIEW_HPP
