#pragma once

#include "Node.h"

#include <iostream>
#include <vector>

namespace linkedlist
{
template<typename T> class SingleLinkedList
{
	public:
		SingleLinkedList() : head(nullptr)
		{

		}

		SingleLinkedList(const std::vector<T>& elements) 
		{
			head = nullptr;
			init(elements);
		}

		~SingleLinkedList()
		{
			clear();
		}

		void init(const std::vector<T>& elements)
		{
			for(auto& e : elements)
				addBack(e);
		}

		std::vector<T> flatten()
		{
			std::vector<T> flat;

			for(Node<T>* n = head; n != nullptr; n = n->next)
				flat.push_back(n->data);

			return flat;
		}

		int length()
		{
			int size = 0;
			for(Node<T>* n = head; n != nullptr; n = n->next)
				size++;

			return size;
		}

		void view()
		{
			for(Node<T>* n = head; n != nullptr; n = n->next)
				std::cout << std::endl << n->data;
		}

		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element, head);
			head = newNode;
		}

		void addBack(const T& element)
		{
			Node<T>* n = head;
			Node<T>* newNode = new Node<T>(element);

			if(!head)
			{
				head = newNode;
			}
			else
			{
				while(n->next)
					n = n->next;

				n->next = newNode;
			}
		}

		void clear()
		{
			Node<T>* n = head;

			while(n)
			{
				Node<T>* toDelete = n;
				n = n->next;

				delete toDelete;
				toDelete = nullptr;
			}

			head = nullptr;
		}

		void remove(const T& element)
		{
			Node<T>* currNode = head;
			Node<T>* prevNode = currNode;

			while(currNode && currNode->data != element)
			{
				prevNode = currNode;
				currNode = currNode->next;
			}

			if(currNode)
				if(currNode == head)
					head = currNode->next;
				else
					prevNode->next = currNode->next;
		}

	private:
		Node<T>* head;			
};
}