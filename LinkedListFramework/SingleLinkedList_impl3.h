#pragma once

#include "Node.h"


namespace linkedlist { namespace singly { namespace impl3 {

template<typename T> class LinkedList
{
	public:
		//================================================================================================================================================================
		LinkedList()
		{
			header = new Node<T>();
			trail  = new Node<T>();

			header->next = trail;
		}

		//================================================================================================================================================================
		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			newNode->next = header->next;
			header->next  = newNode;
		}

		//================================================================================================================================================================
		void addBack(const T& element)
		{
			Node<T>* n = header;
			while(n->next != trail)
				n = n->next;

			Node<T>* newNode = new Node<T>(element);
			n->next = newNode;
			newNode->next = trail;
		}

		//================================================================================================================================================================
		void view()
		{
			std::cout << "sentinelHead -> ";
			for(Node<T>* n = header->next; n != trail; n = n->next)
				std::cout << n->data << " -> ";
			std::cout << "sentinelTrail" << "\n";
		}

	private:
		Node<T>* header;
		Node<T>* trail;
};

} // namespace linkedlist
} // namespace singly
} // namespace impl3