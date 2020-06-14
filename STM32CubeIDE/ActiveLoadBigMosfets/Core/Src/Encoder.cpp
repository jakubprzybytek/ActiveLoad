#include "Encoder.hpp"

void Encoder::reset(uint16_t value, uint16_t minValue, uint16_t maxValue, uint16_t step) {
	this->value = value;
	this->minValue = minValue;
	this->maxValue = maxValue;
	this->step = step;
}

uint16_t Encoder::getValue() {
	return this->value;
}

void Encoder::up() {
	if (this->value < this->maxValue - this->step) {
		this->value += this->step;
	} else {
		this->value = this->maxValue;
	}
}

void Encoder::down() {
	if (this->value > this->minValue + this->step) {
		this->value -= this->step;
	} else {
		this->value = this->minValue;
	}
}
