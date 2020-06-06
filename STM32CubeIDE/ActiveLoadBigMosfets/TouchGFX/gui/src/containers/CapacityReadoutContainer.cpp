#include <gui/containers/CapacityReadoutContainer.hpp>

CapacityReadoutContainer::CapacityReadoutContainer() {
}

void CapacityReadoutContainer::initialize() {
	CapacityReadoutContainerBase::initialize();
	capacityAmpHoursValueTextArea.setWildcard(capacityAmpHoursBuffer);
	capacityWattHoursValueTextArea.setWildcard(capacityWattHoursBuffer);
}

void CapacityReadoutContainer::setTime(uint8_t hour, uint8_t minute, uint8_t second) {
	digitalClock.setTime24Hour(hour, minute, second);
}

void CapacityReadoutContainer::setCapacityAmpHours(float capacityAmpHours) {
	Unicode::snprintfFloat(capacityAmpHoursBuffer, TEXTAREA_SIZE, "%f", capacityAmpHours);
	capacityAmpHoursValueTextArea.invalidate();
}

void CapacityReadoutContainer::setCapacityWattHours(float capacityWattHours) {
	Unicode::snprintfFloat(capacityWattHoursBuffer, TEXTAREA_SIZE, "%f", capacityWattHours);
	capacityWattHoursValueTextArea.invalidate();
}
