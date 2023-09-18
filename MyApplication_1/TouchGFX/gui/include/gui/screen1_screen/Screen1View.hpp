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
    virtual void handleTickEvent();

    void updateProgress(uint16_t tick);

    // Screen1AreaView();
    void updateValue(int value);
protected:

    uint16_t tickCounter;

    int textProgress1Max;
    int textProgress1Min;


    static const int TEXTBUFFER_SIZE = 16;
    Unicode::UnicodeChar textBuffer[TEXTBUFFER_SIZE];
    TextAreaWithOneWildcard textArea;
};

#endif // SCREEN1VIEW_HPP
