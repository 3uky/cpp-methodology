#pragma once

#include <deque>
#include <vector>

namespace basic_elements
{
	class IStack
	{
	public:
		virtual void Push(int value) = 0;
		virtual void Pop() = 0;
		virtual int Top() const = 0;
		virtual bool Empty() const = 0;
	};

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