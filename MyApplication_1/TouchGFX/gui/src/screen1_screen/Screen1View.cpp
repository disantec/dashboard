#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()

{
    tickCounter = 0;
    textProgress1.getRange(textProgress1Min, textProgress1Max);
    
}

void Screen1View::updateProgress(uint16_t tick)
{
    textProgress1.setValue(tick % (textProgress1Max + 1));

}

void Screen1View::updateValue(int value)
{
    Unicode::snprintf(textBuffer, TEXTBUFFER_SIZE, "%d", value);
    textArea.invalidate();
}


void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::handleTickEvent()
{
    tickCounter++;
    updateProgress(tickCounter);
}
