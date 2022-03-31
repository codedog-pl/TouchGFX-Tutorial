#include <gui/model/ModelListener.hpp>



/*
  Sends a message to the model's message queue.
  @param uint32_t id message identifier.
*/
void ModelListener::sendMessage(UIMessage message)
{
	model->messageQueue.push(message);
}
