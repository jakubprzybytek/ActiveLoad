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

void MainView::setVoltageLimit(float voltageLimit) {
	loadSettingsContainer.setVoltageLimit(voltageLimit);
}

void MainView::setCurrentLimit(float currentLimit) {
	loadSettingsContainer.setCurrentLimit(currentLimit);
}

void MainView::setPower(float power) {
	inputReadoutContainer.setPower(power);
}

void MainView::setTemperature(int8_t temperature) {
	termpControlContainer.setRadiatorTemperature(temperature);
}

void MainView::setFanDutyCycle(uint8_t fanDutyCycle) {
	termpControlContainer.setFanDutyCycle(fanDutyCycle);
}

void MainView::setFanRPM(uint16_t fanRPM) {
	termpControlContainer.setFanRPM(fanRPM);
}
