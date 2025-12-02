#pragma once

#include <memory>

// direct dependency (includes) of abstract class (e.g. bussiness logic) on concrete implementation (e.g. database) violates dip principle
// - new implementation like new ConcreteC class would require modification of this class,
// - changes in concrete classes would have impact on this class (compilation required)
// - changes in concrete classes would influence this implementation, you are not isolated from concrete implementation
#include "ConcreteA.h"
#include "ConcreteB.h"

class Abstract
{
public:
    Abstract(std::unique_ptr<ConcreteA> worker) { worker->DoSomething(); };
    Abstract(std::unique_ptr<ConcreteB> worker) { worker->DoSomething(); };
};