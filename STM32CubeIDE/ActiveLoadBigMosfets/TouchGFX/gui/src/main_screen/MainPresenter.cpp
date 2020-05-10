#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::voltageChanged(float voltage) {
	view.setVoltage(voltage);
}

void MainPresenter::currentChanged(float current) {
	view.setCurrent(current);
}
