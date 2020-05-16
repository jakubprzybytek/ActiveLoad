#ifndef LOADSETTINGSCONTAINER_HPP
#define LOADSETTINGSCONTAINER_HPP

#include <gui_generated/containers/LoadSettingsContainerBase.hpp>

class LoadSettingsContainer : public LoadSettingsContainerBase
{
public:
    LoadSettingsContainer();
    virtual ~LoadSettingsContainer() {}

    virtual void initialize();
protected:
};

#endif // LOADSETTINGSCONTAINER_HPP
