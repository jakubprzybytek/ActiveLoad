#include <gui/containers/LargeReadoutContainer.hpp>

LargeReadoutContainer::LargeReadoutContainer() {

}

void LargeReadoutContainer::initialize() {
    LargeReadoutContainerBase::initialize();
    valueTextArea.setWildcard(valueAreaBuffer);
}

void LargeReadoutContainer::setLabel(TypedText text) {
	labelTextArea.setTypedText(text);
	labelTextArea.invalidate();
}

void LargeReadoutContainer::setUnit(TypedText text) {
	unitTextArea.setTypedText(text);
	unitTextArea.invalidate();
}

void LargeReadoutContainer::setValue(float value) {
	Unicode::snprintfFloat(valueAreaBuffer, TEXTAREA_SIZE, "%f", value);
	valueTextArea.invalidate();
}
