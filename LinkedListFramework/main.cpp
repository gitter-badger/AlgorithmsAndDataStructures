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

	list.addBack(1);
	list.addBack(1);
	list.addBack(2);
	list.addBack(2);
	list.addBack(3);
	list.addBack(4);
	list.addBack(4);
	list.addBack(5);
	list.addBack(5);
	list.addBack(5);

	list.view();
	list.removeDuplicates();
	list.view();

	std::cout << "\n\n";
	return 0;
}