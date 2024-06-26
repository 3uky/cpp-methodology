// https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/

#pragma once

#include <memory>

namespace containers
{

template<typename T>
class Node
{
public:
	Node(T data) : m_value(data), next{ nullptr } {}

	T GetValue()
	{
		return m_value;
	}

	Node<T>* Next()
	{
		return next.get();
	}
	
	T m_value;
	std::unique_ptr<Node> next;
};

template<typename T>
class ForwardList
{
public:
	ForwardList() : m_head{ nullptr } {}
	ForwardList(T data) : m_head{ data } {}

	ForwardList(const ForwardList& list)
	{
		Node<T>* root = list.m_head.get();
		Node<T>* pnew_head{ nullptr };

		std::unique_ptr<Node<T>> new_head{nullptr};
		

		while(root)
		{
			auto temp = std::make_unique<Node<T>>(root->GetValue());
			if(new_head == nullptr) // first copy
			{ 
				new_head = std::move(temp);
				pnew_head = new_head.get();
			}
			else
			{
				pnew_head->next = std::move(temp);
				pnew_head = pnew_head->next.get();
			}

			root = root->next.get();
		}

		m_head = std::move(new_head);
	}

	ForwardList(ForwardList&& list)
	{
		m_head = std::move(list.m_head);
	}

	void Push(T data) 
	{
		auto temp{ std::make_unique<Node<T>>(data) };
		if (m_head)
		{
			temp->next = std::move(m_head);
			m_head = std::move(temp);
		}
		else
		{
			m_head = std::move(temp);
		}
	}

	void Pop() 
	{
		if (m_head == nullptr)
			return;
		
		std::unique_ptr<Node<T>> temp = std::move(m_head);
		m_head = std::move(temp->next);
	}

	void Clean()
	{
		while (m_head)
			m_head = std::move(m_head->next);
	}
	
	T Front()
	{
		return Head()->GetValue();
	}

	Node<T>* Head()
	{
		return m_head.get();
	}

	void Reverse()
	{
		ForwardList<T> tmp;

		auto root = Head();
		while (root)
		{
			tmp.Push(root->GetValue());
			root = root->Next();
		}
		Clean();
		m_head = std::move(tmp.m_head);
	}

private:
	std::unique_ptr<Node<T>> m_head;
};

}