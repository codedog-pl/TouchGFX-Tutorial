#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	bool testPinState = BRIDGE_GetTestPinState();
	if (testPinState != lastTestPinState) modelListener->testPinStateChanged(lastTestPinState = testPinState);
	frame++;
	if ((frame % 60) == 0) {
		second++;
		modelListener->secondTick();
	}
}
