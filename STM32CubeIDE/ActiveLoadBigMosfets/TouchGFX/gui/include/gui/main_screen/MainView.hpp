#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setVoltage(float voltage);
    void setCurrent(float current);
    void setPower(float power);

    void setLoadSinkEnabled(bool loadSinkEnabled);
    void setVoltageLimit(float volteageLimit);
    void setCurrentLimit(float currentLimit);
    void setDacValue(uint16_t dacValue);

    void setTime(uint8_t hour, uint8_t minute, uint8_t second);
    void setCapacityAmpHours(float capacityAmpHours);
    void setCapacityWattHours(float capacityWattHours);

    void setTemperature(int8_t temperature);
    void setFanDutyCycle(uint8_t fanDutyCycle);
    void setFanRPM(uint16_t fanRPM);

protected:
};

#endif // MAINVIEW_HPP
