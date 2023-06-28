#pragma once

#include <deque>
#include <vector>

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


	class StackElement
	{
	public:
		StackElement(int value) : data(value) {}
		int data;
		std::unique_ptr<StackElement> next = nullptr;
	};

	class Stack : public IStack
	{
	public:
		Stack() {};
		void Push(int value) override
		{
			auto new_element = std::make_unique<StackElement>(value);
			if (m_top == nullptr)
				m_top = std::move(new_element);
			else
			{
				new_element->next = std::move(m_top);
				m_top = std::move(new_element);
			}
		}

		void Pop() override
		{
			if(m_top != nullptr)
				m_top = std::move(m_top->next);
		}

		int Top() const override
		{
			return m_top->data;
		}

		bool Empty() const override
		{
			return m_top == nullptr;
		}

	private:
		std::unique_ptr<StackElement> m_top;
	};
}