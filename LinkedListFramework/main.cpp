#include "SingleLinkedList_impl1.h" // impl1: head + null
#include "SingleLinkedList_impl2.h" // impl2: head + tail

#include "DoublyLinkedList_impl1.h" // impl1: head + null
#include "DoublyLinkedList_impl2.h" // impl1: head + tail

#include <iostream>
#include <vector>
#include <string>


using namespace linkedlist::doubly::impl2; 


int main()
{
	LinkedList<int> list;
	list.addFront(1);
	list.addFront(2);
	list.addFront(3);
	list.addFront(4);

	list.view();
	std::cout << "\n";
	list.viewReverse();

	std::cout << "\n\n";
	return 0;
}