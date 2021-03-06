#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#if not defined (SIMULATOR)
#include "ApplicationState.hpp"
#include "DebugLogger.hpp"

extern ApplicationState applicationState;
extern DebugLogger logger;
#endif

#if defined (SIMULATOR)
#include "stm32l1xx_hal.h"
#endif

Model::Model() : modelListener(0) {
}

void Model::tick() {
#if not defined (SIMULATOR)
	if (this->voltage != applicationState.voltageReadout) {
		this->voltage = applicationState.voltageReadout;
		this->modelListener->voltageChanged(this->voltage);
	}
	if (this->current != applicationState.currentReadout) {
		this->current = applicationState.currentReadout;
		this->modelListener->currentChanged(this->current);
	}
	if (this->power != applicationState.powerReadout) {
		this->power = applicationState.powerReadout;
		this->modelListener->powerChanged(this->power);
	}

	if (this->loadSinkEnabled != applicationState.loadSinkEnabled) {
		this->loadSinkEnabled = applicationState.loadSinkEnabled;
		this->modelListener->loadSinkEnabledChanged(this->loadSinkEnabled);
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

	if (this->second != applicationState.timer.seconds) {
		this->hour = applicationState.timer.hours;
		this->minute = applicationState.timer.minutes;
		this->second = applicationState.timer.seconds;
		this->modelListener->timeChanged(this->hour, this->minute, this->second);
	}
	if (this->capacityAmpHours != applicationState.chargeAmpHours) {
		this->capacityAmpHours = applicationState.chargeAmpHours;
		this->modelListener->capacityAmpHoursChanged(this->capacityAmpHours);
	}
	if (this->capacityWattHours != applicationState.chargeWattHours) {
		this->capacityWattHours = applicationState.chargeWattHours;
		this->modelListener->capacityWattHoursChanged(this->capacityWattHours);
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

	while (logger.hasLineToConsume()) {
		this->modelListener->lineLogged(logger.consumeLine());
	}

	#endif
}
