#pragma once

#include <memory>

#include "i_stack.h"

namespace containers
{
	class StackElement
	{
	public:
		StackElement(int value) : data(value) {}
		int data;
		std::unique_ptr<StackElement> next = nullptr;
	};
}