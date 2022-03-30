#ifndef COUNTDOWNVIEW_HPP
#define COUNTDOWNVIEW_HPP

#include <gui_generated/countdown_screen/CountdownViewBase.hpp>
#include <gui/countdown_screen/CountdownPresenter.hpp>

class CountdownView : public CountdownViewBase
{
public:
    CountdownView();
    ~CountdownView() {}
    void setupScreen();
    void tearDownScreen();
    void clockUpdate();
    void handleSecondTick();
private:
    uint32_t timeLeft = 10;
};

#endif // COUNTDOWNVIEW_HPP
