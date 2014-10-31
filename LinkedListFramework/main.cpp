#include "SingleLinkedList_impl1.h"
#include "DoublyLinkedList_impl1.h"

#include <iostream>
#include <vector>
#include <string>

using namespace linkedlist::singly::impl1; // impl1: head + null tail
//using namespace linkedlist::single::impl2; // impl2: head + tail
//using namespace linkedlist::single::impl3; // impl3: dummy head + tail

//using namespace linkedlist::doubly::impl1; // impl1: head + null tail


int main()
{
	LinkedList<int> list;
	list.addFront(50);
	list.addFront(40);
	list.addFront(30);
	list.addFront(20);
	list.addFront(10);
	list.insertSorted(1);

	list.view();

	std::cout << "\n\n";
	return 0;
}