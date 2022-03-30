#include <gui/countdown_screen/CountdownView.hpp>
#include <gui/countdown_screen/CountdownPresenter.hpp>

CountdownPresenter::CountdownPresenter(CountdownView& v)
    : view(v)
{

}

void CountdownPresenter::activate()
{

}

void CountdownPresenter::deactivate()
{

}

void CountdownPresenter::secondTick()
{
    view.handleSecondTick();
}
