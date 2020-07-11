#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void voltageChanged(uint16_t voltage) {}
    virtual void currentChanged(uint16_t current) {}
    virtual void powerChanged(uint32_t power) {}

    virtual void loadSinkEnabledChanged(bool loadSinkEnabled) {}
    virtual void voltageLimitChanged(uint16_t voltageLimit) {}
    virtual void currentLimitChanged(uint16_t currentLimit) {}
    virtual void dacValueChanged(uint16_t dacValue) {}

    virtual void timeChanged(uint8_t hour, uint8_t minute, uint8_t second) {}
    virtual void capacityAmpHoursChanged(float capacityAmpHours) {}
    virtual void capacityWattHoursChanged(float capacityWattHours) {}

    virtual void temperatureChanged(int8_t temperature) {}
    virtual void fanDutyCycleChanged(uint8_t fanDutyCycle) {}
    virtual void fanRPMChanged(uint16_t fanRPM) {}

    virtual void lineLogged(char *line) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
