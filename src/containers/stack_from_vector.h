#pragma once

#include <vector>

#include "i_stack.h"

namespace containers
{
	class StackFromVector : public IStack
	{
	public:
		void Push(int value) override
		{
			m_stack.push_back(value);
		}

		void Pop() override
		{
			if (!m_stack.empty())
				m_stack.pop_back();
		}

		int Top() const override
		{
			return m_stack.back();
		}

		bool Empty() const override
		{
			return m_stack.empty();
		}

	private:
		std::vector<int> m_stack;
	};

}