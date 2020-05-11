#ifndef ONETHIRDREADOUTCONTAINER_HPP
#define ONETHIRDREADOUTCONTAINER_HPP

#include <gui_generated/containers/OneThirdReadoutContainerBase.hpp>

class OneThirdReadoutContainer : public OneThirdReadoutContainerBase {

private:
	static const uint16_t TEXTAREA_SIZE = 20;
	touchgfx::Unicode::UnicodeChar valueAreaBuffer[TEXTAREA_SIZE];

public:
    OneThirdReadoutContainer();
    virtual ~OneThirdReadoutContainer() {}

    virtual void initialize();

    void setLabel(TypedText text);
    void setUnit(TypedText text);
    void setValue(float value);
    void setValue(uint8_t value);
    void setValue(int8_t value);

protected:
};

#endif // ONETHIRDREADOUTCONTAINER_HPP
