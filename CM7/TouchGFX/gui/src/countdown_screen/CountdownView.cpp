#include <gui/countdown_screen/CountdownView.hpp>

CountdownView::CountdownView()
{

}

void CountdownView::setupScreen()
{
    CountdownViewBase::setupScreen();
}

void CountdownView::tearDownScreen()
{
    CountdownViewBase::tearDownScreen();
}

void CountdownView::clockUpdate()
{
    clock.setTime24Hour(0, 0, timeLeft);
    clock.invalidate();
}

void CountdownView::handleSecondTick()
{
    if (timeLeft > 0) {
        timeLeft--;
        clockUpdate();
    }
    else application().gotoBoomScreenNoTransition();
}
