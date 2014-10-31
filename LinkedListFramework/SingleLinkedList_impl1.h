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
			// special case. If the list is empty
			if(!head)
			{
				addFront(element);
				return;
			}

			// create the new node
			Node<T>* newNode = new Node<T>(element);

			Node<T>* node = head;
			Node<T>* prev = node;
			// search where it has to be introduced
			while(node != nullptr && newNode->data > node->data)
			{
				prev = node;
				node = node->next;
			}

			// special case if it is the first element
			if(node == head)
			{
				newNode->next = head;
				head = newNode;
			}
			// handle the other cases
			else
			{
				newNode->next = prev->next;
				prev->next = newNode;
			}
		}
		void removeDuplicates()
		{
			for(Node<T>* n = head; n->next != nullptr; n = n->next)
			{
				Node<T>* temp = n->next;
				Node<T>* prev = n;
				while(temp->data == n->data)
				{
					prev = temp;
					temp = temp->next;

					if(!temp->next)
						break;
				}

				// Make sure that if we are the end we exit the loop.
				// otherwise we would have nullptr->next causing a crash
				if(!temp->next)
				{
					n->next = nullptr;
					break;
				}
				else
					if(temp != prev)
						n->next = prev->next;
			}
		}
		T findMiddle()
		{
			Node<T>* curr       = head;
			Node<T>* doubleSkip = head;

			// order is very important. it is evaluated left -> right
			while(doubleSkip->next && doubleSkip->next->next)
			{
				curr = curr->next;
				doubleSkip = doubleSkip->next->next;
			}

			return curr->data;
		}

	private:
		Node<T>* head;			
};

} // namespace impl1
} // namespace single
} // namespace linkedlist