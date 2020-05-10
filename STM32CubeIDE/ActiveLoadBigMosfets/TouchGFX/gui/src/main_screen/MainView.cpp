#include <gui/main_screen/MainView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();

    voltageReadoutContainer.setLabel(touchgfx::TypedText(T_VOLTAGE));
    voltageReadoutContainer.setUnit(touchgfx::TypedText(T_VOLTUNIT));
    currentReadoutContainer.setLabel(touchgfx::TypedText(T_CURRENT));
    currentReadoutContainer.setUnit(touchgfx::TypedText(T_AMPUNIT));
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::setVoltage(float voltage) {
    voltageReadoutContainer.setValue(voltage);
}

void MainView::setCurrent(float current) {
	currentReadoutContainer.setValue(current);
}
