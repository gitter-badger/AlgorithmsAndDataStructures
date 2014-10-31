#pragma once

#include "Node.h"

#include <iostream>
#include <vector>


namespace linkedlist
{
namespace doubly
{
namespace impl1
{
template<typename T> class LinkedList
{
	public:
		LinkedList() : head(nullptr)
		{

		}

		void view()
		{
			std::cout << "head <-> ";
			for(Node<T>* n = head; n != nullptr; n = n->next)
				std::cout << n->data << " <-> ";
			std::cout << "nullptr" << "\n";
		}

		void viewReverse()
		{
			Node<T>* n = head;
			for(; n->next!= nullptr; n = n->next); // go to the end

			Node<T>* tail = n;
			std::cout << "nullptr <-> ";
			for(Node<T>* it = tail; it != nullptr; it = it->prev)
				std::cout << it->data << " <-> ";
			std::cout << "head";
		}

		void addFront(const T& element)
		{
			Node<T>* node = new Node<T>(element);

			if(!head)
			{
				head = node;
				head->next = nullptr;
				head->prev = nullptr;
			}
			else
			{
				head->prev = node;
				node->next = head;

				head = node;
				node->prev = nullptr;
			}
		}

	private:
		Node<T>* head;			
};

} // namespace impl1
} // namespace single
} // namespace linkedlist