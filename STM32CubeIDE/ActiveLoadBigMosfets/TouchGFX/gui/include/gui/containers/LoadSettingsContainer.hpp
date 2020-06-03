#ifndef LOADSETTINGSCONTAINER_HPP
#define LOADSETTINGSCONTAINER_HPP

#include <gui_generated/containers/LoadSettingsContainerBase.hpp>
#include <touchgfx/Color.hpp>

class LoadSettingsContainer: public LoadSettingsContainerBase {

private:
	const colortype SELECTED_BOX_BORDER_COLOR = touchgfx::Color::getColorFrom24BitRGB(141, 181, 255);
	const colortype NOT_SELECTED_BOX_BORDER_COLOR = touchgfx::Color::getColorFrom24BitRGB(70, 70, 70);

	static const uint16_t TEXTAREA_SIZE = 10;
	touchgfx::Unicode::UnicodeChar voltageLimitBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar currentLimitBuffer[TEXTAREA_SIZE];

public:
	LoadSettingsContainer();
	virtual ~LoadSettingsContainer() {
	}

	virtual void initialize();

	void voltageValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);
	void currentValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);

	void setVoltageLimit(float voltageLimit);
	void setCurrentLimit(float currentLimit);

protected:
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> voltageValueBoxClickedCallback;
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> currentValueBoxClickedCallback;

};

#endif // LOADSETTINGSCONTAINER_HPP
