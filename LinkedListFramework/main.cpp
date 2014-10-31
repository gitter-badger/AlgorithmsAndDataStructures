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
	int nrElements = 11;
	for(int i = 0; i < nrElements; i++)
		list.addBack(i);

	std::cout << "Middle: " << list.findMiddle() << "\n";

	std::cout << "\n\n";
	return 0;
}