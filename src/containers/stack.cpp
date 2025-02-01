#include <memory>

#include "stack.h"

namespace containers
{

Stack::Stack()
{
}

void Stack::Push(int value)
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

void Stack::Pop()
{
	if(m_top != nullptr)
		m_top = std::move(m_top->next);
}

int Stack::Top() const
{
	return m_top->data;
}

bool Stack::Empty() const
{
	return m_top == nullptr;
}

}