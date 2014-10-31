#pragma once

#include "Node.h"

#include <iostream>
#include <vector>


namespace linkedlist
{
namespace singly
{
namespace impl1
{
template<typename T> class LinkedList
{
	public:
		LinkedList() : head(nullptr)
		{

		}
		LinkedList(const std::vector<T>& elements) 
		{
			head = nullptr;
			init(elements);
		}
		~LinkedList()
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
			std::cout << "head -> ";
			for(Node<T>* n = head; n != nullptr; n = n->next)
				std::cout << n->data << " -> ";
			std::cout << "nullptr" << "\n";
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

		void insertSorted(const T& element)
		{
			if(!head)
			{
				addFront(element);
				return;
			}

			Node<T>* newNode = new Node<T>(element);

			Node<T>* node = head;
			Node<T>* prev = node;
			while(node != nullptr && newNode->data > node->data)
			{
				prev = node;
				node = node->next;
			}

			if(node == head)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = prev->next;
				prev->next = newNode;
			}
		}
		

	private:
		Node<T>* head;			
};

} // namespace impl1
} // namespace single
} // namespace linkedlist