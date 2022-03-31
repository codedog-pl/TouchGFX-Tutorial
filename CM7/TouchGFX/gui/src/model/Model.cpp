#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifdef SIMULATOR
bool BRIDGE_GetTestPinState() { return true; }
#endif // SIMULATOR

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	bool testPinState = BRIDGE_GetTestPinState();
	if (testPinState != lastTestPinState || frame == 0) modelListener->testPinStateChanged(lastTestPinState = testPinState);
	frame++;
	if ((frame % 60) == 0) {
		second++;
		modelListener->secondTick();
	}
}
