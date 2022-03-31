#ifndef MODEL_HPP
#define MODEL_HPP

/* HAL bridge configuration START */
#ifndef SIMULATOR
extern "C" {
bool BRIDGE_GetTestPinState();
void BRIDGE_SetLED1(bool state);
void BRIDGE_SetLED2(bool state);
void BRIDGE_SetLED3(bool state);
void BRIDGE_SetLED4(bool state);
}
#else
bool BRIDGE_GetTestPinState();
void BRIDGE_SetLED1(bool state);
void BRIDGE_SetLED2(bool state);
void BRIDGE_SetLED3(bool state);
void BRIDGE_SetLED4(bool state);
#endif // !SIMULATOR
/* HAL bridge configuration END */

#include <cstdint>
#include <queue>


enum UIMessageId {
    MSG_SET_LEDS
};

enum UILEDState {
    LEDS_NONE = 0, LEDS_GREEN = 1, LEDS_ORANGE = 2, LEDS_RED = 4, LEDS_BLUE = 8, LEDS_ALL = 15
};

struct UIMessage {

    UIMessageId Id;
    int Parameter;

};


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    std::queue<UIMessage> messageQueue;
protected:
    ModelListener* modelListener;
private:
    uint32_t frame = 0;
    uint32_t second = 0;
    bool lastTestPinState = true;
};

#endif // MODEL_HPP
