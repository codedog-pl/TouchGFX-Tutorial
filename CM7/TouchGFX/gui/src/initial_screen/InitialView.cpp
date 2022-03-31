#include <gui/initial_screen/InitialView.hpp>

InitialView::InitialView()
{

}

void InitialView::setupScreen()
{
    InitialViewBase::setupScreen();
    sensorOverrideToggle.forceState(true);
    sensorOverrideToggle.invalidate();
    gauge1.setValue(coreTemp);
}

void InitialView::tearDownScreen()
{
    InitialViewBase::tearDownScreen();
}

void InitialView::handleTickEvent()
{
    bool sensorOverride = sensorOverrideToggle.getState();
	if (sensorOverride) coolingEnabled = sensorOverride;
    if (coolingEnabled && coreTemp > 20) coreTemp--;
    if (!coolingEnabled && coreTemp < 1000) coreTemp++;
    if (coreTemp == lastCoreTemp) return;
    gauge1.setValue(coreTemp);
    gauge1.invalidate();
    if (coreTemp > 150) {
        application().gotoCountdownScreenWipeTransitionEast();

    }
}

void InitialView::testPinStateChanged(bool state)
{
	coolingEnabled = !state;
}
