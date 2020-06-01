#ifndef LOADSETTINGSCONTAINER_HPP
#define LOADSETTINGSCONTAINER_HPP

#include <gui_generated/containers/LoadSettingsContainerBase.hpp>

class LoadSettingsContainer: public LoadSettingsContainerBase {

private:
	static const uint16_t TEXTAREA_SIZE = 10;
	touchgfx::Unicode::UnicodeChar currentLimitBuffer[TEXTAREA_SIZE];

public:
	LoadSettingsContainer();
	virtual ~LoadSettingsContainer() {
	}

	virtual void initialize();

	void voltageValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);
	void currentValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);

	void setCurrentLimit(float currentLimit);

protected:
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> voltageValueBoxClickedCallback;
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> currentValueBoxClickedCallback;

};

#endif // LOADSETTINGSCONTAINER_HPP
