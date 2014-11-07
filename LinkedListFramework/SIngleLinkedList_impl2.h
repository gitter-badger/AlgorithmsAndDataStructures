#pragma once

#include "Node.h"

#include <iostream>


namespace linkedlist { namespace singly { namespace impl2 {

template<typename T> class LinkedList
{
	public:
		//================================================================================================================================================================
		LinkedList()
		{
			tail = head;
		}

		//================================================================================================================================================================
		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			newNode->next = head;
			head = newNode;
		}

		//================================================================================================================================================================
		void addBack(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			if(!head)
			{
				head = newNode;
				tail = head;
				tail->next = nullptr;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
				tail->next = nullptr;
			}
		}

		//================================================================================================================================================================
		void view()
		{
			std::cout << "head -> ";
			for(Node<T>* n = head; n!= nullptr; n = n->next)
				std::cout << n->data << " -> ";
			std::cout << "tail" << "\n";
		}

	private:
		Node<T>* head;
		Node<T>* tail;

};

} // namespace impl2
} // namespace singly
} // namespace linkedlist