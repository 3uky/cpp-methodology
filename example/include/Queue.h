#pragma once
#include <memory>
#include <list>

namespace containers
{

class IQueue
{
public:
	virtual void Enqueue(int value) = 0; //Enqueue : Inserts a new element at the rear of the queue.
	virtual void Dequeue() = 0; //Dequeue : Removes the front element of the queue and returns it.
	virtual int Peek() const = 0;	//Peek : Returns the front element present in the queue without dequeuing it.
	virtual bool IsEmpty() const = 0; //IsEmpty : Checks if the queue is empty.
	virtual int Size() const = 0; //Size : Returns the total number of elements present in the queue.
};

class QueueFromVector : public IQueue
{
public:
	QueueFromVector() {}

	void Enqueue(int value) override
	{
		m_queue.push_back(value);
	}

	void Dequeue() override
	{
		m_queue.pop_front();
	}

	int Peek() const override
	{
		return m_queue.front();
	}

	bool IsEmpty() const override
	{
		return m_queue.empty();
	}

	int Size() const override
	{
		return static_cast<int>(m_queue.size());
	}

private:
	std::list<int> m_queue;
};


class QueueElement
{
public:
	QueueElement(int value) : data(value) {}

	int data;
	std::shared_ptr<QueueElement> next = nullptr;
};

class Queue : public IQueue
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
