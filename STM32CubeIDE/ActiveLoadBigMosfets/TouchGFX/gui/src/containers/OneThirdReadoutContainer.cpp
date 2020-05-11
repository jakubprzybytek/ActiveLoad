#include <gui/containers/OneThirdReadoutContainer.hpp>

OneThirdReadoutContainer::OneThirdReadoutContainer() { }

void OneThirdReadoutContainer::initialize() {
	OneThirdReadoutContainerBase::initialize();
    valueTextArea.setWildcard(valueAreaBuffer);
}

void OneThirdReadoutContainer::setLabel(TypedText text) {
	labelTextArea.setTypedText(text);
	labelTextArea.invalidate();
}

void OneThirdReadoutContainer::setUnit(TypedText text) {
	unitTextArea.setTypedText(text);
	unitTextArea.invalidate();
}

void OneThirdReadoutContainer::setValue(float value) {
	Unicode::snprintfFloat(valueAreaBuffer, TEXTAREA_SIZE, "%f", value);
	valueTextArea.invalidate();
}

void OneThirdReadoutContainer::setValue(uint8_t value) {
	Unicode::snprintf(valueAreaBuffer, TEXTAREA_SIZE, "%u", value);
	valueTextArea.invalidate();
}

void OneThirdReadoutContainer::setValue(int8_t value) {
	Unicode::snprintf(valueAreaBuffer, TEXTAREA_SIZE, "%d", value);
	valueTextArea.invalidate();
}
