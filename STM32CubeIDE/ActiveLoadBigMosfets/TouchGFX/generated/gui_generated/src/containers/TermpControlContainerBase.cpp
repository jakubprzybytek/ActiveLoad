/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/TermpControlContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

TermpControlContainerBase::TermpControlContainerBase()
{
    setWidth(114);
    setHeight(128);
    background.setPosition(0, 18, 114, 110);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(58, 58, 58));
    background.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(100, 100, 100));
    background.setBorderSize(1);

    labelTextArea.setXY(2, 0);
    labelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(129, 168, 119));
    labelTextArea.setLinespacing(0);
    labelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID18));

    fanRpmValueTextArea.setPosition(40, 104, 44, 22);
    fanRpmValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    fanRpmValueTextArea.setLinespacing(0);
    fanRpmValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID25));

    fanRpmLabelTextArea.setXY(4, 93);
    fanRpmLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    fanRpmLabelTextArea.setLinespacing(0);
    fanRpmLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID24));

    fanRPMUnitTextArea.setXY(85, 109);
    fanRPMUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    fanRPMUnitTextArea.setLinespacing(0);
    fanRPMUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID26));

    fanDutyCycleValueTextArea.setPosition(40, 68, 44, 22);
    fanDutyCycleValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    fanDutyCycleValueTextArea.setLinespacing(0);
    fanDutyCycleValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID22));

    fanDutyCycleLabelTextArea.setXY(4, 56);
    fanDutyCycleLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    fanDutyCycleLabelTextArea.setLinespacing(0);
    fanDutyCycleLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID23));

    radiatorTemperatureUnitTextArea.setPosition(88, 37, 15, 20);
    radiatorTemperatureUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    radiatorTemperatureUnitTextArea.setLinespacing(0);
    radiatorTemperatureUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID17));

    radiatorTemperatureValueTextArea.setPosition(40, 32, 44, 22);
    radiatorTemperatureValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    radiatorTemperatureValueTextArea.setLinespacing(0);
    radiatorTemperatureValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID19));

    radiatorTemperatureLabelTextArea.setXY(4, 19);
    radiatorTemperatureLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    radiatorTemperatureLabelTextArea.setLinespacing(0);
    radiatorTemperatureLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID21));

    fanDutyCycleUnitTextArea.setXY(88, 73);
    fanDutyCycleUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    fanDutyCycleUnitTextArea.setLinespacing(0);
    fanDutyCycleUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID48));

    add(background);
    add(labelTextArea);
    add(fanRpmValueTextArea);
    add(fanRpmLabelTextArea);
    add(fanRPMUnitTextArea);
    add(fanDutyCycleValueTextArea);
    add(fanDutyCycleLabelTextArea);
    add(radiatorTemperatureUnitTextArea);
    add(radiatorTemperatureValueTextArea);
    add(radiatorTemperatureLabelTextArea);
    add(fanDutyCycleUnitTextArea);
}

void TermpControlContainerBase::initialize()
{

}
