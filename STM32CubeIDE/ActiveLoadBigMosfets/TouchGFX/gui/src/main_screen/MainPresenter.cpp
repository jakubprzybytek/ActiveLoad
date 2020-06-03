#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView &v) :
		view(v) {
}

void MainPresenter::activate() {
	this->view.setTime(this->model->getHour(), this->model->getMinute(), this->model->getSecond());
	this->view.setVoltage(this->model->getVoltage());
	this->view.setCurrent(this->model->getCurrent());
	this->view.setVoltageLimit(this->model->getVoltageLimit());
	this->view.setCurrentLimit(this->model->getCurrentLimit());
	this->view.setTemperature(this->model->getTemperature());
	this->view.setFanDutyCycle(this->model->getFanDutyCycle());
	this->view.setFanRPM(this->model->getFanRPM());
}

void MainPresenter::deactivate() {
}

void MainPresenter::timeChanged(uint8_t hour, uint8_t minute, uint8_t second) {
	this->view.setTime(hour, minute, second);
}

void MainPresenter::voltageChanged(float voltage) {
	this->view.setVoltage(voltage);
}

void MainPresenter::currentChanged(float current) {
	this->view.setCurrent(current);
}

void MainPresenter::powerChanged(float power) {
	this->view.setPower(power);
}

void MainPresenter::voltageLimitChanged(float voltageLimit) {
	this->view.setVoltageLimit(voltageLimit);
}

void MainPresenter::currentLimitChanged(float currentLimit) {
	this->view.setCurrentLimit(currentLimit);
}

void MainPresenter::temperatureChanged(int8_t temperature) {
	this->view.setTemperature(temperature);
}

void MainPresenter::fanDutyCycleChanged(uint8_t fanDutyCycle) {
	this->view.setFanDutyCycle(fanDutyCycle);
}

void MainPresenter::fanRPMChanged(uint16_t fanRPM) {
	this->view.setFanRPM(fanRPM);
}

void MainPresenter::selectVoltageLimitForEdit() {
	this->model->selectVoltageLimitForEdit();
}

void MainPresenter::selectCurrentLimitForEdit() {
	this->model->selectCurrentLimitForEdit();
}
