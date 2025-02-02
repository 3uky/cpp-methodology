#pragma once

#include <deque>

#include "i_stack.h"

namespace containers
{
	class StackFromDeque : public IStack
	{
	public:
		void Push(int value) override
		{
			m_stack.push_back(value);
		}

		void Pop() override
		{
			if(!m_stack.empty())
				m_stack.pop_front();
		}

		int Top() const override
		{
			return m_stack.front();
		}

		bool Empty() const override
		{
			return m_stack.empty();
		}

	private:
		std::deque<int> m_stack;
	};

}