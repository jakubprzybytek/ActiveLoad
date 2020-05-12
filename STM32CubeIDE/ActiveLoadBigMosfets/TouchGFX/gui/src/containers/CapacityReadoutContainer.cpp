#include <gui/containers/CapacityReadoutContainer.hpp>

CapacityReadoutContainer::CapacityReadoutContainer() {
}

void CapacityReadoutContainer::initialize() {
	CapacityReadoutContainerBase::initialize();
}

void CapacityReadoutContainer::setTime(uint8_t hour, uint8_t minute, uint8_t second) {
	digitalClock.setTime24Hour(hour, minute, second);
}
