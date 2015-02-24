#include "Node.h"
#include "Algorithm.h"

#include <iostream>


int main()
{
    Node* head = factory::createMultiLevelLinkedList();

	algorithm::flatten(head);
	algorithm::view(head);
    
	std::cout << "\n\n";
    return 0;
}