#ifndef TERMPCONTROLCONTAINER_HPP
#define TERMPCONTROLCONTAINER_HPP

#include <gui_generated/containers/TermpControlContainerBase.hpp>
#include <touchgfx/Color.hpp>

class TermpControlContainer: public TermpControlContainerBase {

private:
	const colortype NORMAL_READOUT_COLOR = touchgfx::Color::getColorFrom24BitRGB(221, 218, 218);
	const colortype ATTENTION_READOUT_COLOR = touchgfx::Color::getColorFrom24BitRGB(236, 179, 37);
	const colortype WARNING_READOUT_COLOR = touchgfx::Color::getColorFrom24BitRGB(255, 96, 96);

	static const uint16_t TEXTAREA_SIZE = 10;
	touchgfx::Unicode::UnicodeChar radiatorTemperatureBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar fanDutyCycleBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar fanRPMBuffer[TEXTAREA_SIZE];

public:
	TermpControlContainer();
	virtual ~TermpControlContainer() {
	}

	virtual void initialize();

	void setRadiatorTemperature(int8_t radiatorTemperature);
	void setFanDutyCycle(uint8_t fanDutyCycle);
	void setFanRPM(uint16_t fanRPM);

protected:

};

#endif // TERMPCONTROLCONTAINER_HPP
