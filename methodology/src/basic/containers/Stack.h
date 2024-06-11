#pragma once

#include <memory>

#include "IStack.h"
#include "StackElement.h"

namespace containers
{
	class Stack : public IStack
	{
	public:
		Stack();

		void Push(int value) override;
		void Pop() override;
		int Top() const override;
		bool Empty() const override;

	private:
		std::unique_ptr<StackElement> m_top;
	};
}