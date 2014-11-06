#pragma once

#include "Node.h"

#include <iostream>


namespace linkedlist { namespace doubly { namespace impl3 {

template<typename T> class LinkedList
{
	public:
		LinkedList()
		{
			header = new Node<T>();
			trail  = new Node<T>();

			header->next = trail;
			trail->prev  = header;
		}

		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			if(header->next == trail)
			{
				newNode->next = trail;
				newNode->prev = header;
				header->next  = newNode;
				trail->prev   = newNode;
			}
			else
			{
				newNode->next      = header->next;
				header->next->prev = newNode;
				newNode->prev	   = header;
				header->next       = newNode;
			}
		}

		void addBack(const T& element)
		{
			if(header->next == trail)
				addFront(element);
			else
			{
				Node<T>* newNode = new Node<T>(element);

				newNode->next     = trail;
				newNode->prev     = trail->prev;
				trail->prev->next = newNode;
				trail->prev       = newNode;
			}
		}

		void view()
		{
			std::cout << "sentinelHead -> ";
			for(Node<T>* n = header->next; n != trail; n = n->next)
				std::cout << n->data << " -> ";
			std::cout << "sentinelTrail" << "\n";
		}

		void viewReverse()
		{
			std::cout << "sentinelTrail -> ";
			for(Node<T>* n = trail->prev; n != header; n = n->prev)
				std::cout << n->data << " -> ";
			std::cout << "sentinelHead" << "\n";
		}

	private:
		Node<T>* header;
		Node<T>* trail;
};

} // namespace linkedlist
} // namespace singly
} // namespace impl3