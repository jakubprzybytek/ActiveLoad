#ifndef MAINPRESENTER_HPP
#define MAINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainView;

class MainPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainPresenter(MainView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainPresenter() {};

    void voltageChanged(float voltage);
    void currentChanged(float current);
    void powerChanged(float power);

    void voltageLimitChanged(float voltageLimit);
    void currentLimitChanged(float currentLimit);
    void dacValueChanged(uint16_t dacValue);

    void timeChanged(uint8_t hour, uint8_t minute, uint8_t second);
    void capacityAmpHoursChanged(float capacityAmpHours);
    void capacityWattHoursChanged(float capacityWattHours);

    void temperatureChanged(int8_t temperature);
    void fanDutyCycleChanged(uint8_t fanDutyCycle);
    void fanRPMChanged(uint16_t fanRPM);

    void startLoadSink();
    void stopLoadSink();
    void resetCounters();
    void selectVoltageLimitForEdit();
    void selectCurrentLimitForEdit();
    void enableVoltageLimit();
    void disableVoltageLimit();

private:
    MainPresenter();

    MainView& view;
};

#endif // MAINPRESENTER_HPP
