#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "LoadState.hpp"

extern LoadState loadState;

Model::Model() : modelListener(0) {

}

void Model::tick() {

	float newVoltage = loadState.voltage;
	float newCurrent = loadState.current;

	if (voltage != newVoltage) {
		voltage = newVoltage;
		modelListener->voltageChanged(voltage);
	}

	if (current != newCurrent) {
		current = newCurrent;
		modelListener->currentChanged(current);
	}

}
