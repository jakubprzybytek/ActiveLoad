#ifndef LARGEREADOUTCONTAINER_HPP
#define LARGEREADOUTCONTAINER_HPP

#include <gui_generated/containers/LargeReadoutContainerBase.hpp>

class LargeReadoutContainer : public LargeReadoutContainerBase
{
private:
	static const uint16_t TEXTAREA_SIZE = 20;
	touchgfx::Unicode::UnicodeChar valueAreaBuffer[TEXTAREA_SIZE];

public:
    LargeReadoutContainer();
    virtual ~LargeReadoutContainer() {}

    virtual void initialize();

    void setLabel(TypedText text);
    void setUnit(TypedText text);
    void setValue(float value);

protected:
};

#endif // LARGEREADOUTCONTAINER_HPP
