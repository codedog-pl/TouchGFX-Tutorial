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
    if (sensorOverrideToggle.getState()) return;
    coreTemp++;
    gauge1.setValue(coreTemp);
    gauge1.invalidate();
    if (coreTemp > 150) {
        application().gotoCountdownScreenWipeTransitionEast();

    }
}
