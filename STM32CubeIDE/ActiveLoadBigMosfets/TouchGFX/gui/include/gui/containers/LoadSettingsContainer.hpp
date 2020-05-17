#ifndef LOADSETTINGSCONTAINER_HPP
#define LOADSETTINGSCONTAINER_HPP

#include <gui_generated/containers/LoadSettingsContainerBase.hpp>

class LoadSettingsContainer: public LoadSettingsContainerBase {
public:
	LoadSettingsContainer();
	virtual ~LoadSettingsContainer() {}

	virtual void initialize();

	void voltageValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);
	void currentValueBoxClickHandler(const BoxWithBorder &b, const ClickEvent &e);

protected:
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> voltageValueBoxClickedCallback;
	Callback<LoadSettingsContainer, const BoxWithBorder&, const ClickEvent&> currentValueBoxClickedCallback;

};

#endif // LOADSETTINGSCONTAINER_HPP
