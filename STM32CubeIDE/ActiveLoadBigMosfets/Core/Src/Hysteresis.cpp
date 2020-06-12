#include "Hysteresis.hpp"

uint8_t Hysteresis::update(uint8_t newSetValue) {
	if (newSetValue > this->lowLimit && newSetValue < this->highLimit) {
		return this->previouslyReturnedValue;
	}

	if (newSetValue <= lowLimit) {
		this->lowLimit = newSetValue > 0 ? newSetValue - 1 : 0;
		this->highLimit = newSetValue + this->hysteresis + 1;
	} else {
		this->lowLimit = newSetValue - this->hysteresis - 1;
		this->highLimit = newSetValue + 1;
	}

	this->previouslyReturnedValue = newSetValue;
	return newSetValue;
}
