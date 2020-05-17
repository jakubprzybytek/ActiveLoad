/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOADSETTINGSCONTAINERBASE_HPP
#define LOADSETTINGSCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/mixins/ClickListener.hpp>

class LoadSettingsContainerBase : public touchgfx::Container
{
public:
    LoadSettingsContainerBase();
    virtual ~LoadSettingsContainerBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::BoxWithBorder background;
    touchgfx::TextArea labelTextArea;
    touchgfx::TextArea currentUnitTextArea;
    touchgfx::ClickListener< touchgfx::BoxWithBorder > currentValueBox;
    touchgfx::TextAreaWithOneWildcard currentValueTextArea;
    touchgfx::TextArea currentLabelTextArea;
    touchgfx::TextArea voltageUnitTextArea;
    touchgfx::ClickListener< touchgfx::BoxWithBorder > voltageValueBox;
    touchgfx::TextAreaWithOneWildcard voltageValueTextArea;
    touchgfx::TextArea voltageLabelTextArea;
    touchgfx::ButtonWithLabel startStopButton;
    touchgfx::ToggleButton voltageLimitEnabledButton;
    touchgfx::TextArea voltageLabelTextArea_1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LoadSettingsContainerBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // LOADSETTINGSCONTAINERBASE_HPP
