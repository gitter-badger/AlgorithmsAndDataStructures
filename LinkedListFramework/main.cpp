#include "SingleLinkedList_impl1.h"
#include "DoublyLinkedList_impl1.h"

#include <iostream>
#include <vector>
#include <string>

using namespace linkedlist::singly::impl1; // impl1: head + null tail
using namespace linkedlist::singly;


int main()
{
	LinkedList<int> list({1, 2, 0, 4, 6, 3});

	list.view();
	list.bubbleSort();
	list.view();

	std::cout << "\n\n";
	return 0;
}