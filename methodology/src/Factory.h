#pragma once

#include <memory>

using namespace std;

namespace design_patterns
{

enum ObjectType
{
    ObjectA,
    ObjectB,
    ObjectC
};

class IObject
{
public:
	virtual ObjectType GetType() const = 0;
};

class Factory
{
  public:
      static unique_ptr<IObject> MakeObject(ObjectType choice);
};

class MyObjectA: public IObject
{
  public:
    ObjectType GetType() const override
    {
        return ObjectA;
    }
};
class MyObjectB: public IObject
{
  public:
      ObjectType GetType() const override
      {
          return ObjectB;
      }
};
class MyObjectC : public IObject
{
public:
    ObjectType GetType() const override
    {
        return ObjectC;
    }
};

unique_ptr<IObject> Factory::MakeObject(ObjectType choice)
{
    switch (choice) {
    case ObjectA:
        return std::make_unique<MyObjectA>();
    case ObjectB:
        return std::make_unique<MyObjectB>();
    default:
        return std::make_unique<MyObjectC>();
    }
}

}