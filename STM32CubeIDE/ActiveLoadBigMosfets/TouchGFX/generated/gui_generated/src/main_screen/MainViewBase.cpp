/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

MainViewBase::MainViewBase() :
    flexButtonCallback(this, &MainViewBase::flexButtonCallbackHandler),
    capacityReadoutContainerRequestTimerResetCallback(this, &MainViewBase::capacityReadoutContainerRequestTimerResetCallbackHandler),
    loadSettingsContainerSelectVoltageLimitForEditCallback(this, &MainViewBase::loadSettingsContainerSelectVoltageLimitForEditCallbackHandler),
    loadSettingsContainerSelectCurrentLimitForEditCallback(this, &MainViewBase::loadSettingsContainerSelectCurrentLimitForEditCallbackHandler),
    loadSettingsContainerStartLoadSinkCallback(this, &MainViewBase::loadSettingsContainerStartLoadSinkCallbackHandler),
    loadSettingsContainerStopLoadSinkCallback(this, &MainViewBase::loadSettingsContainerStopLoadSinkCallbackHandler),
    loadSettingsContainerEnableVoltageLimitCallback(this, &MainViewBase::loadSettingsContainerEnableVoltageLimitCallbackHandler),
    loadSettingsContainerDisableVoltageLimitCallback(this, &MainViewBase::loadSettingsContainerDisableVoltageLimitCallbackHandler)
{

    background.setPosition(0, 0, 240, 320);
    background.setColor(touchgfx::Color::getColorFrom24BitRGB(46, 46, 46));
    background.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(100, 100, 100));
    background.setBorderSize(2);

    termpControlContainer.setXY(160, 194);

    inputReadoutContainer.setXY(4, 4);

    capacityReadoutContainer.setXY(4, 194);
    capacityReadoutContainer.setRequestTimerResetCallback(capacityReadoutContainerRequestTimerResetCallback);

    titleTextArea.setPosition(0, 3, 236, 25);
    titleTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(158, 199, 255));
    titleTextArea.setLinespacing(0);
    titleTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID47));

    loadSettingsContainer.setXY(4, 92);
    loadSettingsContainer.setSelectVoltageLimitForEditCallback(loadSettingsContainerSelectVoltageLimitForEditCallback);
    loadSettingsContainer.setSelectCurrentLimitForEditCallback(loadSettingsContainerSelectCurrentLimitForEditCallback);
    loadSettingsContainer.setStartLoadSinkCallback(loadSettingsContainerStartLoadSinkCallback);
    loadSettingsContainer.setStopLoadSinkCallback(loadSettingsContainerStopLoadSinkCallback);
    loadSettingsContainer.setEnableVoltageLimitCallback(loadSettingsContainerEnableVoltageLimitCallback);
    loadSettingsContainer.setDisableVoltageLimitCallback(loadSettingsContainerDisableVoltageLimitCallback);

    resetConfirmationModalWindow.setBackground(touchgfx::BitmapId(BITMAP_MODALBACKGROUND_ID), 18, 88);
    resetConfirmationModalWindow.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(97, 97, 97));
    resetConfirmationModalWindow.setShadeAlpha(0);
    resetConfirmationModalWindow.hide();

    warningImage.setXY(10, 15);
    warningImage.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_ALERT_32_ID));
    resetConfirmationModalWindow.add(warningImage);

    resetTextArea.setXY(64, 23);
    resetTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(61, 58, 58));
    resetTextArea.setLinespacing(0);
    resetTextArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID66));
    resetConfirmationModalWindow.add(resetTextArea);

    cancelButton.setBoxWithBorderPosition(0, 0, 66, 50);
    cancelButton.setBorderSize(3);
    cancelButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(2, 73, 109), touchgfx::Color::getColorFrom24BitRGB(5, 133, 175), touchgfx::Color::getColorFrom24BitRGB(24, 112, 201), touchgfx::Color::getColorFrom24BitRGB(81, 143, 204));
    cancelButton.setText(TypedText(T_SINGLEUSEID73));
    cancelButton.setTextPosition(0, 16, 66, 50);
    cancelButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(158, 213, 250), touchgfx::Color::getColorFrom24BitRGB(73, 107, 163));
    cancelButton.setPosition(28, 75, 66, 50);
    cancelButton.setAction(flexButtonCallback);
    resetConfirmationModalWindow.add(cancelButton);

    resetButton.setBoxWithBorderPosition(0, 0, 66, 50);
    resetButton.setBorderSize(3);
    resetButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(112, 23, 23), touchgfx::Color::getColorFrom24BitRGB(112, 23, 23), touchgfx::Color::getColorFrom24BitRGB(255, 0, 0), touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    resetButton.setText(TypedText(T_SINGLEUSEID74));
    resetButton.setTextPosition(0, 16, 66, 50);
    resetButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(252, 219, 219), touchgfx::Color::getColorFrom24BitRGB(252, 219, 219));
    resetButton.setPosition(114, 75, 66, 50);
    resetButton.setAction(flexButtonCallback);
    resetConfirmationModalWindow.add(resetButton);

    add(background);
    add(termpControlContainer);
    add(inputReadoutContainer);
    add(capacityReadoutContainer);
    add(titleTextArea);
    add(loadSettingsContainer);
    add(resetConfirmationModalWindow);
}

void MainViewBase::setupScreen()
{
    termpControlContainer.initialize();
    inputReadoutContainer.initialize();
    capacityReadoutContainer.initialize();
    loadSettingsContainer.initialize();
}

void MainViewBase::capacityReadoutContainerRequestTimerResetCallbackHandler()
{
    //ShowResetConfirmationModalWindowInteraction
    //When capacityReadoutContainer requestTimerReset show resetConfirmationModalWindow
    //Show resetConfirmationModalWindow
    resetConfirmationModalWindow.setVisible(true);
    resetConfirmationModalWindow.invalidate();
}

void MainViewBase::loadSettingsContainerSelectVoltageLimitForEditCallbackHandler()
{
    //selectingVoltageLimitForEdit
    //When loadSettingsContainer selectVoltageLimitForEdit execute C++ code
    //Execute C++ code
    this->presenter->selectVoltageLimitForEdit();
}

void MainViewBase::loadSettingsContainerSelectCurrentLimitForEditCallbackHandler()
{
    //selectingCurrentLimitForEdit
    //When loadSettingsContainer selectCurrentLimitForEdit execute C++ code
    //Execute C++ code
    this->presenter->selectCurrentLimitForEdit();
}

void MainViewBase::loadSettingsContainerStartLoadSinkCallbackHandler()
{
    //StartLoadSink
    //When loadSettingsContainer startLoadSink execute C++ code
    //Execute C++ code
    this->presenter->startLoadSink();
}

void MainViewBase::loadSettingsContainerStopLoadSinkCallbackHandler()
{
    //StopLoadSink
    //When loadSettingsContainer stopLoadSink execute C++ code
    //Execute C++ code
    this->presenter->stopLoadSink();
}

void MainViewBase::loadSettingsContainerEnableVoltageLimitCallbackHandler()
{
    //EnableVoltageLimit
    //When loadSettingsContainer enableVoltageLimit execute C++ code
    //Execute C++ code
    this->presenter->enableVoltageLimit();
}

void MainViewBase::loadSettingsContainerDisableVoltageLimitCallbackHandler()
{
    //DisableVolatgeLimit
    //When loadSettingsContainer disableVoltageLimit execute C++ code
    //Execute C++ code
    this->presenter->disableVoltageLimit();
}

void MainViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &cancelButton)
    {
        //HideResetConfirmationModelWindowInteraction
        //When cancelButton clicked hide resetConfirmationModalWindow
        //Hide resetConfirmationModalWindow
        resetConfirmationModalWindow.setVisible(false);
        resetConfirmationModalWindow.invalidate();
    }
    else if (&src == &resetButton)
    {
        //ConfirmResetCounters
        //When resetButton clicked hide resetConfirmationModalWindow
        //Hide resetConfirmationModalWindow
        resetConfirmationModalWindow.setVisible(false);
        resetConfirmationModalWindow.invalidate();

        //PerformResetCounters
        //When ConfirmResetCounters completed execute C++ code
        //Execute C++ code
        this->presenter->resetCounters();
    }
}
