#pragma once

template<typename T>
class ListElement
{
public:
	ListElement(T value) : m_value(value) {}

	T m_value;
	std::shared_ptr<ListElement> next = nullptr;
	std::shared_ptr<ListElement> previous;
};

template<typename T>
class LinkedList
{
public:
	void Reverse();
	void Insert(T value)
	{
		auto new_element = std::make_shared<ListElement<T>>(value);

		if (m_head == nullptr)
		{
			m_head = new_element;
		}
		else
		{
			const auto tail = GetTail();
			tail->next = new_element;
			new_element->previous = tail;
		}
	}

	auto Front()
	{
		return m_head->m_value;
	}

	auto Get(unsigned int pos)
	{
		return GetElement(pos)->m_value;
	}

	void Remove(int pos)
	{
		auto element = GetElement(pos);

		if(element->previous != nullptr)
			element->previous->next = element->next;
		if (element->next != nullptr)
			element->next->previous = element->previous;
		element.reset();
	}


private:
	auto GetTail()
	{
		if (m_head == nullptr)
			return m_head;

		auto tail = m_head;
		while (tail->next != nullptr)
			tail = tail->next;
		return tail;
	}

	auto GetElement(unsigned int pos)
	{
		auto element = m_head;
		for (unsigned int i = 0; i < pos; i++)
			element = element->next;
		return element;
	}


	std::shared_ptr<ListElement<T>> m_head = nullptr; // first element
};