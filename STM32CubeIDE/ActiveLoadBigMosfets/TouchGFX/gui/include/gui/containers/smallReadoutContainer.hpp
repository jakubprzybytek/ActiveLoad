#ifndef SMALLREADOUTCONTAINER_HPP
#define SMALLREADOUTCONTAINER_HPP

#include <gui_generated/containers/SmallReadoutContainerBase.hpp>

class SmallReadoutContainer : public SmallReadoutContainerBase
{
private:
	static const uint16_t TEXTAREA_SIZE = 20;
	touchgfx::Unicode::UnicodeChar valueAreaBuffer[TEXTAREA_SIZE];

public:
    SmallReadoutContainer();
    virtual ~SmallReadoutContainer() {}

    virtual void initialize();

    void setLabel(TypedText text);
    void setUnit(TypedText text);
    void setValue(float value);
    void setValue(int8_t value);

protected:
};

#endif // SMALLREADOUTCONTAINER_HPP
