#include <gui/containers/SmallReadoutContainer.hpp>

SmallReadoutContainer::SmallReadoutContainer() {

}

void SmallReadoutContainer::initialize() {
    SmallReadoutContainerBase::initialize();
    valueTextArea.setWildcard(valueAreaBuffer);
}

void SmallReadoutContainer::setLabel(TypedText text) {
	labelTextArea.setTypedText(text);
	labelTextArea.invalidate();
}

void SmallReadoutContainer::setUnit(TypedText text) {
	unitTextArea.setTypedText(text);
	unitTextArea.invalidate();
}

void SmallReadoutContainer::setValue(float value) {
	Unicode::snprintfFloat(valueAreaBuffer, TEXTAREA_SIZE, "%f", value);
	valueTextArea.invalidate();
}

void SmallReadoutContainer::setValue(int8_t value) {
	Unicode::snprintf(valueAreaBuffer, TEXTAREA_SIZE, "%d", value);
	valueTextArea.invalidate();
}
