#include "Node.h"
#include "Algorithm.h"

#include <iostream>


int main()
{
	Node* list = factory::createRandPrevList();

	algorithm::ViewNext(list);
	std::cout << "\n";
	algorithm::ViewPrev(list);


	std::cout << "\n" << "\n";
	return 0;
}