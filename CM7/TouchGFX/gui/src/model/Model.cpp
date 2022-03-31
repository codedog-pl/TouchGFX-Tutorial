#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifdef SIMULATOR // bridge definitions for simulator
bool BRIDGE_GetTestPinState() { return true; }
void BRIDGE_SetLED1(bool state) { }
void BRIDGE_SetLED2(bool state) { }
void BRIDGE_SetLED3(bool state) { }
void BRIDGE_SetLED4(bool state) { }
#endif // SIMULATOR

Model::Model() : modelListener(0)
{

}

/*
  Model tick executed on each UI frame, typically @60FPS.
 */
void Model::tick()
{
    // message handling:
    if (!messageQueue.empty()) {
        UIMessage m = messageQueue.front();
        messageQueue.pop();
        switch (m.Id)
        {
        case MSG_SET_LEDS:
        {
            UILEDState ls = (UILEDState)m.Parameter;
            BRIDGE_SetLED1((ls & LEDS_GREEN) > 0);
            BRIDGE_SetLED2((ls & LEDS_ORANGE) > 0);
            BRIDGE_SetLED3((ls & LEDS_RED) > 0);
            BRIDGE_SetLED4((ls & LEDS_BLUE) > 0);
        }
            break;
        default:
            break;
        }
    }
    // GPIO polling:
    bool testPinState = BRIDGE_GetTestPinState();
    if (testPinState != lastTestPinState || frame == 0) modelListener->testPinStateChanged(lastTestPinState = testPinState);
    // frame counter, second ticks:
    frame++;
    if ((frame % 60) == 0) {
        second++;
        modelListener->secondTick();
    }
}

