#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "ApplicationState.hpp"

extern ApplicationState applicationState;

Model::Model() :
		modelListener(0) {
}

void Model::tick() {
	if (this->second != applicationState.time.Seconds) {
		this->hour = applicationState.time.Hours;
		this->minute = applicationState.time.Minutes;
		this->second = applicationState.time.Seconds;
		this->modelListener->timeChanged(this->hour, this->minute, this->second);
	}

	if (this->voltage != applicationState.voltage) {
		this->voltage = applicationState.voltage;
		this->modelListener->voltageChanged(this->voltage);
		this->modelListener->powerChanged(this->voltage * this->current);
	}
	if (this->current != applicationState.current) {
		this->current = applicationState.current;
		this->modelListener->currentChanged(this->current);
		this->modelListener->powerChanged(this->voltage * this->current);
	}

	if (this->voltageLimit != applicationState.voltageLimit) {
		this->voltageLimit = applicationState.voltageLimit;
		this->modelListener->voltageLimitChanged(this->voltageLimit);
	}
	if (this->currentLimit != applicationState.currentLimit) {
		this->currentLimit = applicationState.currentLimit;
		this->modelListener->currentLimitChanged(this->currentLimit);
	}
	if (this->dacValue != applicationState.loadLevel) {
		this->dacValue = applicationState.loadLevel;
		this->modelListener->dacValueChanged(this->dacValue);
	}

	if (this->temperature != applicationState.temperature) {
		this->temperature = applicationState.temperature;
		this->modelListener->temperatureChanged(this->temperature);
	}
	if (this->fanDutyCycle != applicationState.fanDutyCycle) {
		this->fanDutyCycle = applicationState.fanDutyCycle;
		this->modelListener->fanDutyCycleChanged(this->fanDutyCycle);
	}
	if (this->fanRPM != applicationState.fanRPM) {
		this->fanRPM = applicationState.fanRPM;
		this->modelListener->fanRPMChanged(this->fanRPM);
	}

	if (applicationState.currentLimitInEdit != this->currentLimitInEdit) {
		applicationState.currentLimitInEdit = this->currentLimitInEdit;
		applicationState.fieldToEditChanged = true;
	}
}
