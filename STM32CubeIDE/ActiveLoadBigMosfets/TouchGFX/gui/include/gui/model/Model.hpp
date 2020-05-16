#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdio.h>

class ModelListener;

class Model
{
private:
	uint8_t hour;
	uint8_t minute;
	uint8_t second;

	float voltage;
	float current;

	int8_t temperature;
	uint8_t fanDutyCycle;
	uint16_t fanRPM;

public:
    Model();

    void bind(ModelListener* listener) {
        modelListener = listener;
    }

    void tick();

    uint8_t getHour() {
    	return this->hour;
    }

    uint8_t getMinute() {
    	return this->minute;
    }

    uint8_t getSecond() {
    	return this->second;
    }

    float getVoltage() {
    	return this->voltage;
    }

    float getCurrent() {
    	return this->current;
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
