#ifndef CAPACITYREADOUTCONTAINER_HPP
#define CAPACITYREADOUTCONTAINER_HPP

#include <gui_generated/containers/CapacityReadoutContainerBase.hpp>

class CapacityReadoutContainer: public CapacityReadoutContainerBase {

public:
	CapacityReadoutContainer();
	virtual ~CapacityReadoutContainer() {
	}

	virtual void initialize();

	void setTime(uint8_t hour, uint8_t minute, uint8_t second);

protected:

};

#endif // CAPACITYREADOUTCONTAINER_HPP
