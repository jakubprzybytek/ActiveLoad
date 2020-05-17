#include <gui/containers/LoadSettingsContainer.hpp>
#include <touchgfx/Color.hpp>

LoadSettingsContainer::LoadSettingsContainer() :
		voltageValueBoxClickedCallback(this, &LoadSettingsContainer::voltageValueBoxClickHandler),
		currentValueBoxClickedCallback(this, &LoadSettingsContainer::currentValueBoxClickHandler) {
	voltageValueBox.setClickAction(voltageValueBoxClickedCallback);
	currentValueBox.setClickAction(currentValueBoxClickedCallback);
}

void LoadSettingsContainer::initialize() {
	LoadSettingsContainerBase::initialize();
}

void LoadSettingsContainer::voltageValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &evt) {
	if (&b == &voltageValueBox) {
		voltageValueBox.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(141, 181, 255));
		currentValueBox.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(97, 97, 97));
		voltageValueBox.invalidate();
		currentValueBox.invalidate();
	}
}

void LoadSettingsContainer::currentValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &evt) {
	if (&b == &currentValueBox) {
		voltageValueBox.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(97, 97, 97));
		currentValueBox.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(141, 181, 255));
		voltageValueBox.invalidate();
		currentValueBox.invalidate();
	}
}
