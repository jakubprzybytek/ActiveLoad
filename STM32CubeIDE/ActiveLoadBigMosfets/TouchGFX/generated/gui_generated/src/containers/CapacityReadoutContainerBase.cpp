/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/CapacityReadoutContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

CapacityReadoutContainerBase::CapacityReadoutContainerBase() :
    flexButtonCallback(this, &CapacityReadoutContainerBase::flexButtonCallbackHandler),
    requestTimerResetCallback(0)
{
    setWidth(152);
    setHeight(122);
    background.setPosition(0, 18, 152, 104);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(45, 45, 45));
    background.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(100, 100, 100));
    background.setBorderSize(1);

    labelTextArea.setXY(2, 0);
    labelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(139, 136, 182));
    labelTextArea.setLinespacing(0);
    labelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID39));

    capacityAmpHoursUnitTextArea.setXY(100, 80);
    capacityAmpHoursUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    capacityAmpHoursUnitTextArea.setLinespacing(0);
    capacityAmpHoursUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID40));

    capacityAmpHoursValueTextArea.setPosition(7, 75, 90, 23);
    capacityAmpHoursValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    capacityAmpHoursValueTextArea.setLinespacing(0);
    capacityAmpHoursValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID41));

    capacityLabelTextArea.setXY(4, 59);
    capacityLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    capacityLabelTextArea.setLinespacing(0);
    capacityLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID42));

    elapsedTimeLabelTextArea.setXY(4, 19);
    elapsedTimeLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    elapsedTimeLabelTextArea.setLinespacing(0);
    elapsedTimeLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID45));

    digitalClock.setPosition(3, 33, 77, 21);
    digitalClock.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    digitalClock.setTypedText(touchgfx::TypedText(T_SINGLEUSEID46));
    digitalClock.displayLeadingZeroForHourIndicator(true);
    digitalClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock.setTime24Hour(0, 0, 0);

    capacityWattHoursUnitTextArea.setXY(100, 103);
    capacityWattHoursUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    capacityWattHoursUnitTextArea.setLinespacing(0);
    capacityWattHoursUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID70));

    capacityWattHoursValueTextArea.setPosition(7, 98, 90, 23);
    capacityWattHoursValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    capacityWattHoursValueTextArea.setLinespacing(0);
    capacityWattHoursValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID71));

    resetButton.setBoxWithBorderPosition(0, 0, 65, 49);
    resetButton.setBorderSize(3);
    resetButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(2, 73, 109), touchgfx::Color::getColorFrom24BitRGB(5, 133, 175), touchgfx::Color::getColorFrom24BitRGB(24, 112, 201), touchgfx::Color::getColorFrom24BitRGB(81, 143, 204));
    resetButton.setText(TypedText(T_SINGLEUSEID72));
    resetButton.setTextPosition(0, 12, 65, 49);
    resetButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(158, 213, 250), touchgfx::Color::getColorFrom24BitRGB(77, 107, 163));
    resetButton.setPosition(84, 24, 65, 49);
    resetButton.setAction(flexButtonCallback);

    add(background);
    add(labelTextArea);
    add(capacityAmpHoursUnitTextArea);
    add(capacityAmpHoursValueTextArea);
    add(capacityLabelTextArea);
    add(elapsedTimeLabelTextArea);
    add(digitalClock);
    add(capacityWattHoursUnitTextArea);
    add(capacityWattHoursValueTextArea);
    add(resetButton);
}

void CapacityReadoutContainerBase::initialize()
{

}

void CapacityReadoutContainerBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &resetButton)
    {
        //timerRequestInteraction
        //When resetButton clicked emit requestTimerReset callback
        //Emit callback
        emitRequestTimerResetCallback();
    }
}
