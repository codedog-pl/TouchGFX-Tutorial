#ifndef INITIALVIEW_HPP
#define INITIALVIEW_HPP

#include <gui_generated/initial_screen/InitialViewBase.hpp>
#include <gui/initial_screen/InitialPresenter.hpp>

class InitialView : public InitialViewBase
{
public:
    InitialView();
    ~InitialView() {}
    void setupScreen();
    void tearDownScreen();
    void handleTickEvent();
    void testPinStateChanged(bool state);
    void sensorOverrideChanged();
private:
    uint32_t coreTemp = 20;
    uint32_t lastCoreTemp = 0;
    bool sensorOverride = true;
    bool sensorState = true;
    bool coolingEnabled = true;
};

#endif // INITIALVIEW_HPP
