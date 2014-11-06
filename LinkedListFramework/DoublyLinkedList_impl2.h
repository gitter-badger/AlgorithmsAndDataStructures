#pragma once

namespace linkedlist { namespace doubly { namespace impl2 {

template<typename T> class LinkedList
{
	public:
		LinkedList()
		{
			head = nullptr;
			tail = head;
		}

		void removeFront()
		{
			if(!head)
				return; 

			if(tail == head)
			{
				delete tail;
				head = tail = nullptr;
				return;
			}

			Node<T>* toRemove = head;
			head = head->next;

			delete toRemove;
		}

		void removeBack()
		{
			if(!tail)
				return;

			if(tail == head)
			{
				delete head;
				tail = head = nullptr;
				return;
			}

			Node<T>* toRemove = tail;

			tail = tail->prev;
			tail->next = nullptr;

			delete toRemove;
		}

		void remove(const T& element)
		{
			Node<T>* n = head;

			while(n != nullptr && n->data != element)
				n = n->next;

			if(n == head)
				removeFront();
			else 
				if(n == tail)
					removeBack();
				else
				{
					Node<T>* toRemove = n;
					n->next->prev = n->prev;
					n->prev->next = n->next;

					delete toRemove;
				}
		}

		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			if(!head)
			{
				head = newNode;
				tail = head;
			}
			else
			{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
		}

		void addBack(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			if(!head)
			{
				head = newNode;
				tail = head;
			}
			else
			{
				newNode->prev = tail;
				tail->next = newNode;
				tail = newNode;
			}
		}

		void view()
		{
			std::cout << "head -> ";
			for(Node<T>* n = head; n != nullptr; n = n->next)
				std::cout << n->data << " -> ";
			std::cout << "tail";
		}

		void viewReverse()
		{
			std::cout << "tail -> ";
			for(Node<T>* n = tail; n != nullptr; n = n->prev)
				std::cout << n->data << " -> ";
			std::cout << "head";
		}

	private:
		Node<T>* head;
		Node<T>* tail;
};

} // namespace linkedlist
} // namespace doubly
} // namespace impl2