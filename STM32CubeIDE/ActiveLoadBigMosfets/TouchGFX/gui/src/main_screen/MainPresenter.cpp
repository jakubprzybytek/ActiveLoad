#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v) : view(v) {}

void MainPresenter::activate() {
	this->view.setTime(this->model->getHour(), this->model->getMinute(), this->model->getSecond());
	this->view.setVoltage(this->model->getVoltage());
	this->view.setCurrent(this->model->getCurrent());
	this->view.setTemperature(this->model->getTemperature());
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

void MainPresenter::temperatureChanged(int8_t temperature) {
	this->view.setTemperature(temperature);
}
