#ifndef TERMPCONTROLCONTAINER_HPP
#define TERMPCONTROLCONTAINER_HPP

#include <gui_generated/containers/TermpControlContainerBase.hpp>

class TermpControlContainer: public TermpControlContainerBase {

private:
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
