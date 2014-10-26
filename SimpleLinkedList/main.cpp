#include "IList.h"
#include "SingleLinkedList.h"

#include <iostream>
#include <memory>


int main()
{
	std::unique_ptr<IList> linkedList = std::make_unique<SingleLinkedList>();
	linkedList->addFront(0);
	linkedList->addFront(1);
	linkedList->addFront(2);
	linkedList->addFront(3);
	linkedList->addFront(4);

	linkedList->remove(2);

	linkedList->view();
	std::cout << std::endl << "Found: " << linkedList->find(-1);



	std::cout << std::endl;
	return 0;
}