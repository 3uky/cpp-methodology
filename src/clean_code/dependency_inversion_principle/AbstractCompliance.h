#pragma once

#include <memory>

// Abstract class is not source code dependet (include) on ConcreteA.h or ConcreteB.h just on Interface.h
// there exists just run-time dependency of Abstract class on ConcreteA class
// class is isolated from concrete implementation and isolated development is possible
#include "Interface.h"

class Abstract
{
public:
    Abstract(std::unique_ptr<Interface> worker) { worker->DoSomething(); };
};

// in main or in some factory would be Abstract class object instanciate as follow:
// Abstract abstract(std::make_unique<ConcreteA>());