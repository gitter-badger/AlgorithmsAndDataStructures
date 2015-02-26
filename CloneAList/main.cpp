#include "Node.h"
#include "Algorithm.h"

#include <iostream>


int main()
{
	Node* list = factory::createRandPrevList();

	Node* clonedList = algorithm::Clone(list);

	algorithm::ViewNext(clonedList);


	std::cout << "\n" << "\n";
	return 0;
}