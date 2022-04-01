#include <gui/initial_screen/InitialView.hpp>

InitialView::InitialView()
{

}

void InitialView::setupScreen()
{
    InitialViewBase::setupScreen();
    sensorOverride = true;
    sensorOverrideToggle.forceState(sensorOverride);
    sensorOverrideToggle.invalidate();
    gauge1.setValue(coreTemp);
    presenter->sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_GREEN });
}

void InitialView::tearDownScreen()
{
    InitialViewBase::tearDownScreen();
}

void InitialView::handleTickEvent()
{
    if (coolingEnabled && coreTemp > 20) coreTemp--;
    if (!coolingEnabled && coreTemp < 1000) coreTemp++;
    if (coreTemp == lastCoreTemp) return;
    gauge1.setValue(coreTemp);
    gauge1.invalidate();
    if (coreTemp < 20) presenter->sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_BLUE });
    else if (coreTemp >= 20 && coreTemp < 50) presenter->sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_GREEN });
    else if (coreTemp >= 50 && coreTemp < 100) presenter->sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_ORANGE });
    else if (coreTemp > 100) presenter->sendMessage({ MSG_SET_LEDS, HALBridge::LEDS_RED });
    if (coreTemp > 150) {
        application().gotoCountdownScreenWipeTransitionEast();

    }
}

void InitialView::testPinStateChanged(bool state)
{
    sensorState = state;
    coolingEnabled = sensorOverride ? true : !state;
}

void InitialView::sensorOverrideChanged()
{
    sensorOverride = sensorOverrideToggle.getState();
    coolingEnabled = sensorOverride ? true : !sensorState;

}
