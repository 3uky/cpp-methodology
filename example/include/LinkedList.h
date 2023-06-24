#pragma once

#include "ILinkedList.h"

template<typename T>
class ListElement
{
public:
	ListElement(T value) : m_value(value) {}

	T m_value;
	std::shared_ptr<ListElement> next = nullptr;
	std::shared_ptr<ListElement> previous = nullptr;
};

template<typename T>
class LinkedList : public ILinkedList<T>
{
public:
	void Insert(T value) override
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

	void Remove(unsigned int pos) override
	{
		auto element = GetElement(pos);

		if (element->previous != nullptr)
			element->previous->next = element->next;
		if (element->next != nullptr)
			element->next->previous = element->previous;
		element.reset();
	}

	T Get(unsigned int pos) const override
	{
		return GetElement(pos)->m_value;
	}

	T Front() const override
	{
		return m_head->m_value;
	}

	T Back() const override
	{
		return GetTail()->m_value;
	}

	void Swap(unsigned int pos_1, unsigned int pos_2) override
	{
		auto element_1 = GetElement(pos_1);
		auto element_2 = GetElement(pos_2);
		auto temp = element_1->m_value;
		element_1->m_value = element_2->m_value;
		element_2->m_value = temp;
	}

	void Reverse() override
	{
		const int count = Count();
		for (int i = 0, j = count - 1 ; i < count / 2; i++, j--)
			Swap(i, j);
	}

	unsigned int Count() const override
	{
		int count;
		auto element = m_head;
		for (count = 0; element != nullptr; count++)
			element = element->next;
		return count;
	}

private:
	std::shared_ptr<ListElement<T>> GetTail() const
	{
		if (m_head == nullptr)
			return m_head;

		auto tail = m_head;
		while (tail->next != nullptr)
			tail = tail->next;
		return tail;
	}

	std::shared_ptr<ListElement<T>> GetElement(unsigned int pos) const
	{
		auto element = m_head;
		for (unsigned int i = 0; i < pos; i++)
			element = element->next;
		return element;
	}

	std::shared_ptr<ListElement<T>> m_head = nullptr; // first element
};