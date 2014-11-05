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

		void addFront(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			newNode->next = head;
			head = newNode;
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