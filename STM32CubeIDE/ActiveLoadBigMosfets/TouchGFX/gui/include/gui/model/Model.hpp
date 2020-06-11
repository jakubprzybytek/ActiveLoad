#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdio.h>

class ModelListener;

class Model
{
private:
	float voltage;
	float current;
	float power;

	float voltageLimit;
	float currentLimit;

	uint16_t dacValue;

	uint8_t hour;
	uint8_t minute;
	uint8_t second;

	float capacityAmpHours;
	float capacityWattHours;

	int8_t temperature;
	uint8_t fanDutyCycle;
	uint16_t fanRPM;

public:
    Model();

    void bind(ModelListener* listener) {
        modelListener = listener;
    }

    void tick();

    float getVoltage() {
    	return this->voltage;
    }

    float getCurrent() {
    	return this->current;
    }

    float getPower() {
    	return this->power;
    }

    float getVoltageLimit() {
    	return this->voltageLimit;
    }

    float getCurrentLimit() {
    	return this->currentLimit;
    }

    uint16_t getDacValue() {
    	return this->dacValue;
    }

    uint8_t getHour() {
    	return this->hour;
    }

    uint8_t getMinute() {
    	return this->minute;
    }

    uint8_t getSecond() {
    	return this->second;
    }

    float getCapacityAmpHours() {
    	return this->capacityAmpHours;
    }

    float getCapacityWattHours() {
    	return this->capacityWattHours;
    }

    int8_t getTemperature() {
    	return this->temperature;
    }

    uint8_t getFanDutyCycle() {
    	return this->fanDutyCycle;
    }

    uint16_t getFanRPM() {
    	return this->fanRPM;
    }

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
