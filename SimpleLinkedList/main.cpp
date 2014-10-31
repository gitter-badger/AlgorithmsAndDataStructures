#include "IList.h"
#include "SingleLinkedList.h"

#include <iostream>
#include <memory>


int main()
{
	int nrElements = 20;
	SingleLinkedList linkedList;

	for(int i = 0; i < nrElements; i++)
		linkedList.addFront(i);

	//linkedList.reverse();
	linkedList.viewReversed();



	std::cout << std::endl;
	return 0;
}