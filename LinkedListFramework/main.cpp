#include "SingleLinkedList.h"

#include <iostream>


int main()
{
	linkedlist::SingleLinkedList<int> list({1, 1, 3});

	list.remove(4);

	list.view();


	return 0;
}