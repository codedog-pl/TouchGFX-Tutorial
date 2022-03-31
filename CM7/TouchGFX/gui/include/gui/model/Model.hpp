#ifndef MODEL_HPP
#define MODEL_HPP

/* HAL bridge configuration START */
#ifndef SIMULATOR
extern "C" bool BRIDGE_GetTestPinState();
#else
bool BRIDGE_GetTestPinState();
#endif // !SIMULATOR
/* HAL bridge configuration END */

#include <cstdint>

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
protected:
    ModelListener* modelListener;
private:
    uint32_t frame = 0;
    uint32_t second = 0;
    bool lastTestPinState = true;
};

#endif // MODEL_HPP
