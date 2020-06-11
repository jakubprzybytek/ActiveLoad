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
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/mixins/ClickListener.hpp>

class LoadSettingsContainerBase : public touchgfx::Container
{
public:
    LoadSettingsContainerBase();
    virtual ~LoadSettingsContainerBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setSelectCurrentLimitForEditCallback(touchgfx::GenericCallback<>& callback)
    {
        this->selectCurrentLimitForEditCallback = &callback;
    }
    void setSelectVoltageLimitForEditCallback(touchgfx::GenericCallback<>& callback)
    {
        this->selectVoltageLimitForEditCallback = &callback;
    }
    void setStartLoadSinkCallback(touchgfx::GenericCallback<>& callback)
    {
        this->startLoadSinkCallback = &callback;
    }
    void setStopLoadSinkCallback(touchgfx::GenericCallback<>& callback)
    {
        this->stopLoadSinkCallback = &callback;
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitSelectCurrentLimitForEditCallback()
    {
        if (selectCurrentLimitForEditCallback && selectCurrentLimitForEditCallback->isValid())
        {
            this->selectCurrentLimitForEditCallback->execute();
        }
    }
    virtual void emitSelectVoltageLimitForEditCallback()
    {
        if (selectVoltageLimitForEditCallback && selectVoltageLimitForEditCallback->isValid())
        {
            this->selectVoltageLimitForEditCallback->execute();
        }
    }
    virtual void emitStartLoadSinkCallback()
    {
        if (startLoadSinkCallback && startLoadSinkCallback->isValid())
        {
            this->startLoadSinkCallback->execute();
        }
    }
    virtual void emitStopLoadSinkCallback()
    {
        if (stopLoadSinkCallback && stopLoadSinkCallback->isValid())
        {
            this->stopLoadSinkCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::BoxWithBorder background;
    touchgfx::TextArea currentUnitTextArea;
    touchgfx::ClickListener< touchgfx::BoxWithBorder > currentValueBox;
    touchgfx::TextAreaWithOneWildcard currentValueTextArea;
    touchgfx::ToggleButton voltageLimitEnabledButton;
    touchgfx::TextArea voltageLimitEnableLabelTextArea;
    touchgfx::ClickListener< touchgfx::BoxWithBorder > voltageValueBox;
    touchgfx::TextArea voltageUnitTextArea;
    touchgfx::TextAreaWithOneWildcard voltageValueTextArea;
    touchgfx::TextArea voltageLabelTextArea;
    touchgfx::TextArea labelTextArea;
    touchgfx::TextAreaWithOneWildcard dacValueTextArea;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ToggleButtonTrigger > > startStopButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LoadSettingsContainerBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<LoadSettingsContainerBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* selectCurrentLimitForEditCallback;
    touchgfx::GenericCallback<>* selectVoltageLimitForEditCallback;
    touchgfx::GenericCallback<>* startLoadSinkCallback;
    touchgfx::GenericCallback<>* stopLoadSinkCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // LOADSETTINGSCONTAINERBASE_HPP
