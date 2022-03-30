#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	frame++;
	if ((frame % 60) == 0) {
		second++;
		modelListener->secondTick();
	}
}