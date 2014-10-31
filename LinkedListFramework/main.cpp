#include "SingleLinkedList_impl1.h"

#include <iostream>
#include <vector>
#include <string>

using namespace linkedlist::single::impl1; // impl1: head + null tail
//using namespace linkedlist::single::impl2; // impl2: head + tail
//using namespace linkedlist::single::impl3; // impl3: dummy head + tail

int main()
{
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	std::cout << "\n\n";
	return 0;
}