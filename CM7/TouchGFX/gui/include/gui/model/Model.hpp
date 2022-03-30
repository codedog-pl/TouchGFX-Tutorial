#ifndef MODEL_HPP
#define MODEL_HPP

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
    uint32_t frame = 0;
    uint32_t second = 0;
};

#endif // MODEL_HPP
