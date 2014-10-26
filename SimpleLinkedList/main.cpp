#include "IList.h"
#include "SingleLinkedList.h"

#include <iostream>
#include <memory>


int main()
{
	int nrElements = 20;
	std::unique_ptr<IList> linkedList = std::make_unique<SingleLinkedList>();

	for(int i = 0; i < nrElements; i++)
		linkedList->addFront(i);

	linkedList->reverse();
	linkedList->view();



	std::cout << std::endl;
	return 0;
}