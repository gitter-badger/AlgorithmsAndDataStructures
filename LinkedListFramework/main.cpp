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
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);
	list.addBack(4);

	list.view();
	std::cout << "\n";
	list.viewReverse();

	std::cout << "\n\n";
	return 0;
}