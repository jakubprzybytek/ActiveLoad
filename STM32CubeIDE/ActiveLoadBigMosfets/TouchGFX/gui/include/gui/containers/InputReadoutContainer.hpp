#ifndef INPUTREADOUTCONTAINER_HPP
#define INPUTREADOUTCONTAINER_HPP

#include <gui_generated/containers/InputReadoutContainerBase.hpp>

class InputReadoutContainer: public InputReadoutContainerBase {

private:
	static const uint16_t TEXTAREA_SIZE = 10;
	touchgfx::Unicode::UnicodeChar voltageBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar currentBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar powerBuffer[TEXTAREA_SIZE];

public:
	InputReadoutContainer();
	virtual ~InputReadoutContainer() {
	}

	virtual void initialize();
	void setVoltage(float voltage);
	void setCurrent(float current);
	void setPower(float power);

protected:

};

#endif // INPUTREADOUTCONTAINER_HPP
