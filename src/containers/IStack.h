#pragma once

namespace containers
{

class IStack
{
public:
	virtual void Push(int value) = 0;
	virtual void Pop() = 0;
	virtual int Top() const = 0;
	virtual bool Empty() const = 0;
};

}