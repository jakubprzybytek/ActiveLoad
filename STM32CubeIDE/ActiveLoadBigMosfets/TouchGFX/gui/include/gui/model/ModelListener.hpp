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

    virtual void timeChanged(uint8_t hour, uint8_t minute, uint8_t second) {}

    virtual void voltageChanged(float voltage) {}
    virtual void currentChanged(float current) {}
    virtual void powerChanged(float power) {}

    virtual void voltageLimitChanged(float currentLimit) {}
    virtual void currentLimitChanged(float currentLimit) {}

    virtual void temperatureChanged(int8_t temperature) {}
    virtual void fanDutyCycleChanged(uint8_t fanDutyCycle) {}
    virtual void fanRPMChanged(uint16_t fanRPM) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
