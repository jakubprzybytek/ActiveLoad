#include <gui/main_screen/MainView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainView::MainView() { }

void MainView::setupScreen() {
    MainViewBase::setupScreen();

    voltageReadoutContainer.setLabel(touchgfx::TypedText(T_VOLTAGE));
    voltageReadoutContainer.setUnit(touchgfx::TypedText(T_VOLTUNIT));
    currentReadoutContainer.setLabel(touchgfx::TypedText(T_CURRENT));
    currentReadoutContainer.setUnit(touchgfx::TypedText(T_AMPUNIT));
    powerReadoutContainer.setLabel(touchgfx::TypedText(T_POWER));
    powerReadoutContainer.setUnit(touchgfx::TypedText(T_POWERUNIT));

    temperatureReadoutContainer.setLabel(touchgfx::TypedText(T_TEMPERATURE));
    temperatureReadoutContainer.setUnit(touchgfx::TypedText(T_TEMPERATUREUNIT));
    fanDutyCycleReadoutContainer.setLabel(touchgfx::TypedText(T_FANDUTYCYCLE));
    fanDutyCycleReadoutContainer.setUnit(touchgfx::TypedText(T_FANDUTYCYCLEUNIT));
}

void MainView::tearDownScreen() {
    MainViewBase::tearDownScreen();
}

void MainView::setTime(uint8_t hour, uint8_t minute, uint8_t second) {
	digitalClock.setTime24Hour(hour, minute, second);
}

void MainView::setVoltage(float voltage) {
    voltageReadoutContainer.setValue(voltage);
}

void MainView::setCurrent(float current) {
	currentReadoutContainer.setValue(current);
}

void MainView::setPower(float power) {
	powerReadoutContainer.setValue(power);
}

void MainView::setTemperature(int8_t temperature) {
	temperatureReadoutContainer.setValue(temperature);
}

void MainView::setDutyCycle(uint8_t dutyCycle) {
	fanDutyCycleReadoutContainer.setValue(dutyCycle);
}
