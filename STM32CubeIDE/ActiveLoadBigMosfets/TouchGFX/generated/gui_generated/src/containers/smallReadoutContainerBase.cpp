/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/SmallReadoutContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SmallReadoutContainerBase::SmallReadoutContainerBase()
{
    setWidth(120);
    setHeight(44);
    background.setPosition(4, 19, 96, 25);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(65, 65, 65));
    background.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(134, 134, 134));
    background.setBorderSize(1);

    unitTextArea.setXY(103, 19);
    unitTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 157, 157));
    unitTextArea.setLinespacing(0);
    unitTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4));

    labelTextArea.setXY(6, 0);
    labelTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(180, 179, 179));
    labelTextArea.setLinespacing(0);
    labelTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5));

    valueTextArea.setPosition(6, 21, 91, 20);
    valueTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(221, 218, 218));
    valueTextArea.setLinespacing(0);
    valueTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID6));

    add(background);
    add(unitTextArea);
    add(labelTextArea);
    add(valueTextArea);
}

void SmallReadoutContainerBase::initialize()
{

}
