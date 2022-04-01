#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{
	lastTestPinState = HALBridge::getTestPinState();
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
        switch (m.id)
        {
        case MSG_SET_LEDS:
        	HALBridge::setLEDs(m.parameter);
            break;
        default:
            break;
        }
    }
    // GPIO polling:
    bool testPinState = HALBridge::getTestPinState();
    if (frame == 0 || testPinState != lastTestPinState) modelListener->testPinStateChanged(lastTestPinState = testPinState);
    // frame counter, second ticks:
    frame++;
    if ((frame % 60) == 0) {
        second++;
        modelListener->secondTick();
    }
}

