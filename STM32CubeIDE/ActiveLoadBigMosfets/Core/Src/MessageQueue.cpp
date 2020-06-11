#include "MessageQueue.hpp"

void MessageQueue::submit(uint8_t message) {
	this->messages.push(message);
}

bool MessageQueue::messageWaiting() {
	return !this->messages.empty();
}

uint8_t MessageQueue::getMessage() {
	uint8_t messageToReturn = this->messages.front();
	this->messages.pop();
	return messageToReturn;
}
