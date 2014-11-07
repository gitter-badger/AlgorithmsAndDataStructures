#pragma once

template<typename T> class Dequeue
{
	public:
		//================================================================================================================================================================
		Dequeue()
		{
			header = new Node();
			trail  = new Node();

			header->next = trail;
			trail->prev  = header;
		}

		//================================================================================================================================================================
		void addFront(const T& item)
		{
			Node* newNode      = new Node(item);

			newNode->next      = header->next;
			newNode->prev      = header;
			header->next->prev = newNode;
			header->next       = newNode;
		}

		//================================================================================================================================================================
		void addBack(const T& item)
		{
			Node* newNode     = new Node(item);

			newNode->next     = trail;
			newNode->prev     = trail->prev;
			trail->prev->next = newNode;
			trail->prev       = newNode;
		}

		//================================================================================================================================================================
		void removeFront()
		{
			Node* toRemove = header;
			header         = header->next;

			delete toRemove;
		}

		//================================================================================================================================================================
		void removeBack()
		{
			Node* toRemove = trail;
			trail          = trail->prev;

			delete toRemove;
		}

		//================================================================================================================================================================
		T getFront()
		{
			return header->next->data;
		}

		//================================================================================================================================================================
		T getBack()
		{
			return trail->prev->data;
		}

		//================================================================================================================================================================
		bool isEmpty()
		{
			return header->next == trail;
		}

	private:
		class Node
		{
			public:
				Node(T data) : data(data)
				{
					next = nullptr;
					prev = nullptr;
				}
				Node()
				{
					next = nullptr;
					prev = nullptr;
				}

				Node* next;
				Node* prev;
				T data;
		};

		Node* header;
		Node* trail;
};