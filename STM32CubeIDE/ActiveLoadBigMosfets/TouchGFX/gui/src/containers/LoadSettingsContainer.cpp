#include <gui/containers/LoadSettingsContainer.hpp>

LoadSettingsContainer::LoadSettingsContainer() :
		voltageValueBoxClickedCallback(this, &LoadSettingsContainer::voltageValueBoxClickHandler),
		currentValueBoxClickedCallback(this, &LoadSettingsContainer::currentValueBoxClickHandler) {
	voltageValueBox.setClickAction(voltageValueBoxClickedCallback);
	currentValueBox.setClickAction(currentValueBoxClickedCallback);
}

void LoadSettingsContainer::initialize() {
	LoadSettingsContainerBase::initialize();
	voltageValueTextArea.setWildcard(voltageLimitBuffer);
	currentValueTextArea.setWildcard(currentLimitBuffer);
}

void LoadSettingsContainer::voltageValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &evt) {
	if (&b == &voltageValueBox) {
		voltageValueBox.setBorderColor(SELECTED_BOX_BORDER_COLOR);
		currentValueBox.setBorderColor(NOT_SELECTED_BOX_BORDER_COLOR);
		voltageValueBox.invalidate();
		currentValueBox.invalidate();

		emitSelectVoltageLimitForEditCallback();
	}
}

void LoadSettingsContainer::currentValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &evt) {
	if (&b == &currentValueBox) {
		voltageValueBox.setBorderColor(NOT_SELECTED_BOX_BORDER_COLOR);
		currentValueBox.setBorderColor(SELECTED_BOX_BORDER_COLOR);
		voltageValueBox.invalidate();
		currentValueBox.invalidate();

		emitSelectCurrentLimitForEditCallback();
	}
}

void LoadSettingsContainer::setVoltageLimit(float voltageLimit) {
	Unicode::snprintfFloat(voltageLimitBuffer, TEXTAREA_SIZE, "%.1f", voltageLimit);
	voltageValueTextArea.invalidate();
}

void LoadSettingsContainer::setCurrentLimit(float currentLimit) {
	Unicode::snprintfFloat(currentLimitBuffer, TEXTAREA_SIZE, "%.3f", currentLimit);
	currentValueTextArea.invalidate();
}
