#include <gui/boom_screen/BoomView.hpp>
#include <gui/boom_screen/BoomPresenter.hpp>

BoomPresenter::BoomPresenter(BoomView& v)
    : view(v)
{

}

void BoomPresenter::activate()
{
    sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_NONE });
}

void BoomPresenter::deactivate()
{

}
