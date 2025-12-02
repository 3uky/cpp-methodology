#pragma once
#include <memory>
#include <list>

#include "i_queue.h"

namespace containers
{

class QueueElement
{
public:
	QueueElement(int value) : data(value) {}

	int data;
	std::shared_ptr<QueueElement> next = nullptr;
};

class QueueFromSharedPointer : public IQueue
{
public:
	void Enqueue(int value) override
	{
		const auto new_element = std::make_shared<QueueElement>(value);
		if (m_front == nullptr)
		{
			m_front = new_element;
			m_back = m_front;
		}
		else
		{
			m_back->next = new_element;
			m_back = new_element;
		}
	}

	void Dequeue() override
	{
		if (m_front == nullptr)
			return;

		m_front = m_front->next;

		if (m_front == nullptr)
			m_back = nullptr;		
	}

	int Peek() const override
	{
		if (m_front == nullptr)
			throw;

		return m_front->data;
		
	}

	bool IsEmpty() const override
	{
		return m_front == nullptr;
	}

	int Size() const override
	{
		int size = 0;
		std::shared_ptr<QueueElement> tmp = m_front;

		while (tmp != nullptr)
		{
			tmp = tmp->next;
			size++;
		}

		return size;
	}

private:
	std::shared_ptr<QueueElement> m_front = nullptr;
	std::shared_ptr<QueueElement> m_back = nullptr;
};
	
}
