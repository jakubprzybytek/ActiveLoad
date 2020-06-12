#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

#include "MessageQueue.hpp"

MainPresenter::MainPresenter(MainView &v) : view(v) {
}

void MainPresenter::activate() {
	this->view.setVoltage(this->model->getVoltage());
	this->view.setCurrent(this->model->getCurrent());
	this->view.setPower(this->model->getPower());
	this->view.setVoltageLimit(this->model->getVoltageLimit());
	this->view.setCurrentLimit(this->model->getCurrentLimit());
	this->view.setDacValue(this->model->getDacValue());
	this->view.setTime(this->model->getHour(), this->model->getMinute(), this->model->getSecond());
	this->view.setCapacityAmpHours(this->model->getCapacityAmpHours());
	this->view.setCapacityWattHours(this->model->getCapacityWattHours());
	this->view.setTemperature(this->model->getTemperature());
	this->view.setFanDutyCycle(this->model->getFanDutyCycle());
	this->view.setFanRPM(this->model->getFanRPM());
}

void MainPresenter::deactivate() {
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

void MainPresenter::dacValueChanged(uint16_t dacValue) {
	this->view.setDacValue(dacValue);
}

void MainPresenter::timeChanged(uint8_t hour, uint8_t minute, uint8_t second) {
	this->view.setTime(hour, minute, second);
}

void MainPresenter::capacityAmpHoursChanged(float capacityAmpHours) {
	this->view.setCapacityAmpHours(capacityAmpHours);
}

void MainPresenter::capacityWattHoursChanged(float capacityWattHours) {
	this->view.setCapacityWattHours(capacityWattHours);
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

void MainPresenter::startLoadSink() {
	MessageQueue::getInstance().submit(START_LOAD_SINK);
}

void MainPresenter::stopLoadSink() {
	MessageQueue::getInstance().submit(STOP_LOAD_SINK);
}

void MainPresenter::resetCounters() {
	MessageQueue::getInstance().submit(RESET_COUNTERS);
}

void MainPresenter::selectVoltageLimitForEdit() {
	MessageQueue::getInstance().submit(SELECT_VOLTAGE_LIMIT_FOR_EDIT);
}

void MainPresenter::selectCurrentLimitForEdit() {
	MessageQueue::getInstance().submit(SELECT_CURRENT_LIMIT_FOR_EDIT);
}

void MainPresenter::enableVoltageLimit() {
	MessageQueue::getInstance().submit(ENABLE_VOLTAGE_LIMIT);
}

void MainPresenter::disableVoltageLimit() {
	MessageQueue::getInstance().submit(DISABLE_VOLTAGE_LIMIT);
}
