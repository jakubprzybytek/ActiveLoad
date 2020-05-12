#include <gui/main_screen/MainView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainView::MainView() {
}

void MainView::setupScreen() {
	MainViewBase::setupScreen();
}

void MainView::tearDownScreen() {
	MainViewBase::tearDownScreen();
}

void MainView::setTime(uint8_t hour, uint8_t minute, uint8_t second) {
	capacityReadoutContainer.setTime(hour, minute, second);
}

void MainView::setVoltage(float voltage) {
	inputReadoutContainer.setVoltage(voltage);
}

void MainView::setCurrent(float current) {
	inputReadoutContainer.setCurrent(current);
}

void MainView::setPower(float power) {
	inputReadoutContainer.setPower(power);
}

void MainView::setTemperature(int8_t temperature) {
	termpControlContainer.setRadiatorTemperature(temperature);
}

void MainView::setDutyCycle(uint8_t dutyCycle) {
	termpControlContainer.setFanDutyCycle(dutyCycle);
}
