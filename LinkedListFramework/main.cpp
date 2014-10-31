#include "SingleLinkedList_impl1.h"
#include "DoublyLinkedList_impl1.h"

#include <iostream>
#include <vector>
#include <string>

using namespace linkedlist::singly::impl1; // impl1: head + null tail
using namespace linkedlist::singly;

template<typename T>
void view(Node<T>* head)
{
	Node<T>* curr = head;

	while(curr)
	{
		std::cout << curr->data << "\n";
		curr = curr->next;
	}
}

template<typename T>
int loop(Node<T>* head)
{
	Node<T>* slow = head;
	Node<T>* fast = head;
	
	while(true)
	{
		if(!fast)
			return -1;

		fast = fast->next;

		if(!fast)
			return -1;

		fast = fast->next;
		slow = slow->next;

		if(fast == slow)
		{
			int size = 0;
			do
			{
				fast = fast->next->next;
				slow = slow->next;
				size++;
			}
			while(fast != slow);
			return size;
		}
	}

	return -1;
}

int main()
{
	Node<int> n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n4; // loop

	LinkedList<int> list(&n1);

	std::cout << "loop: " << list.loop() << "\n";


	std::cout << "\n\n";
	return 0;
}