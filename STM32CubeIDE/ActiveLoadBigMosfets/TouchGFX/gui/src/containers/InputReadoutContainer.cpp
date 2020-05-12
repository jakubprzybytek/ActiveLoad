#include <gui/containers/InputReadoutContainer.hpp>

InputReadoutContainer::InputReadoutContainer() {
}

void InputReadoutContainer::initialize() {
	InputReadoutContainerBase::initialize();
	voltageValueTextArea.setWildcard(voltageBuffer);
	currentValueTextArea.setWildcard(currentBuffer);
	powerValueTextArea.setWildcard(powerBuffer);
}

void InputReadoutContainer::setVoltage(float voltage) {
	Unicode::snprintfFloat(voltageBuffer, TEXTAREA_SIZE, "%f", voltage);
	voltageValueTextArea.invalidate();
}

void InputReadoutContainer::setCurrent(float current) {
	Unicode::snprintfFloat(currentBuffer, TEXTAREA_SIZE, "%f", current);
	currentValueTextArea.invalidate();
}

void InputReadoutContainer::setPower(float power) {
	Unicode::snprintfFloat(powerBuffer, TEXTAREA_SIZE, "%.2f", power);
	powerValueTextArea.invalidate();
}
