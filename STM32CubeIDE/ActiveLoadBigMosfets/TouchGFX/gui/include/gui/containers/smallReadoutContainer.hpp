#ifndef SMALLREADOUTCONTAINER_HPP
#define SMALLREADOUTCONTAINER_HPP

#include <gui_generated/containers/smallReadoutContainerBase.hpp>

class smallReadoutContainer : public smallReadoutContainerBase
{
public:
    smallReadoutContainer();
    virtual ~smallReadoutContainer() {}

    virtual void initialize();
protected:
};

#endif // SMALLREADOUTCONTAINER_HPP
