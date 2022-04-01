#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/model/HALBridge.hpp>
#include <cstdint>
#include <queue>

enum UIMessageId {
    MSG_SET_LEDS
};

struct UIMessage {
    UIMessageId id;
    int parameter;
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
