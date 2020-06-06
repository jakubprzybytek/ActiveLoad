#ifndef CAPACITYREADOUTCONTAINER_HPP
#define CAPACITYREADOUTCONTAINER_HPP

#include <gui_generated/containers/CapacityReadoutContainerBase.hpp>

class CapacityReadoutContainer: public CapacityReadoutContainerBase {

private:
	static const uint16_t TEXTAREA_SIZE = 10;
	touchgfx::Unicode::UnicodeChar capacityAmpHoursBuffer[TEXTAREA_SIZE];
	touchgfx::Unicode::UnicodeChar capacityWattHoursBuffer[TEXTAREA_SIZE];

public:
	CapacityReadoutContainer();
	virtual ~CapacityReadoutContainer() {
	}

	virtual void initialize();

	void setTime(uint8_t hour, uint8_t minute, uint8_t second);
	void setCapacityAmpHours(float capacityAmpHours);
	void setCapacityWattHours(float capacityWattHours);

protected:

};

#endif // CAPACITYREADOUTCONTAINER_HPP
