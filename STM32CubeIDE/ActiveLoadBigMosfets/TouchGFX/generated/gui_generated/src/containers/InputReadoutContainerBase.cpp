/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/InputReadoutContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

InputReadoutContainerBase::InputReadoutContainerBase()
{
    setWidth(232);
    setHeight(88);
    background.setPosition(0, 16, 232, 72);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(45, 45, 45));
    background.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(100, 100, 100));
    background.setBorderSize(1);

    labelTextArea.setPosition(2, 0, 113, 18);
    labelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(228, 156, 156));
    labelTextArea.setLinespacing(0);
    labelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID27));

    currentUnitTextArea.setPosition(86, 64, 15, 20);
    currentUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    currentUnitTextArea.setLinespacing(0);
    currentUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID30));

    currentValueTextArea.setPosition(4, 58, 80, 30);
    currentValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    currentValueTextArea.setLinespacing(0);
    currentValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID31));

    voltageUnitTextArea.setXY(86, 36);
    voltageUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    voltageUnitTextArea.setLinespacing(0);
    voltageUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID33));

    voltageValueTextArea.setPosition(4, 30, 80, 30);
    voltageValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    voltageValueTextArea.setLinespacing(0);
    voltageValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID34));

    voltageLabelTextArea.setXY(4, 19);
    voltageLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    voltageLabelTextArea.setLinespacing(0);
    voltageLabelTextArea.setTypedText(touchgfx::TypedText(T_VOLTAGECURRENT));

    powerLabelTextArea.setPosition(186, 19, 40, 15);
    powerLabelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    powerLabelTextArea.setLinespacing(0);
    powerLabelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID36));

    powerValueTextArea.setPosition(99, 35, 112, 42);
    powerValueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    powerValueTextArea.setLinespacing(0);
    powerValueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID37));

    powerUnitTextArea.setPosition(211, 52, 26, 21);
    powerUnitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    powerUnitTextArea.setLinespacing(0);
    powerUnitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID38));

    add(background);
    add(labelTextArea);
    add(currentUnitTextArea);
    add(currentValueTextArea);
    add(voltageUnitTextArea);
    add(voltageValueTextArea);
    add(voltageLabelTextArea);
    add(powerLabelTextArea);
    add(powerValueTextArea);
    add(powerUnitTextArea);
}

void InputReadoutContainerBase::initialize()
{

}
