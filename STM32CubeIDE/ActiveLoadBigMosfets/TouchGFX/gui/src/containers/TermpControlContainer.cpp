#include <texts/TextKeysAndLanguages.hpp>
#include <gui/containers/TermpControlContainer.hpp>

TermpControlContainer::TermpControlContainer() {
}

void TermpControlContainer::initialize() {
	TermpControlContainerBase::initialize();
	radiatorTemperatureValueTextArea.setWildcard(radiatorTemperatureBuffer);
	fanDutyCycleValueTextArea.setWildcard(fanDutyCycleBuffer);
	fanRpmValueTextArea.setWildcard(fanRPMBuffer);
}

void TermpControlContainer::setRadiatorTemperature(int8_t radiatorTemperature) {
	Unicode::snprintf(radiatorTemperatureBuffer, TEXTAREA_SIZE, "%d", radiatorTemperature);

	radiatorTemperatureValueTextArea.setColor(
			radiatorTemperature < 40 ? NORMAL_READOUT_COLOR : (radiatorTemperature < 50 ? ATTENTION_READOUT_COLOR : WARNING_READOUT_COLOR));

	radiatorTemperatureValueTextArea.invalidate();
}

void TermpControlContainer::setFanDutyCycle(uint8_t fanDutyCycle) {
	if (fanDutyCycle > 0) {
		Unicode::snprintf(fanDutyCycleBuffer, TEXTAREA_SIZE, "%u", fanDutyCycle);
		fanDutyCycleValueTextArea.invalidate();
	} else {
		Unicode::strncpy(fanDutyCycleBuffer, TypedText(T_OFF).getText(), TEXTAREA_SIZE);
		fanDutyCycleValueTextArea.invalidate();
	}
}

void TermpControlContainer::setFanRPM(uint16_t fanRPM) {
	Unicode::snprintf(fanRPMBuffer, TEXTAREA_SIZE, "%u", fanRPM);
	fanRpmValueTextArea.invalidate();
}
