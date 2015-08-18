#include "RecursiveLinkedList.h"
#include "Node.h"

#include <iostream>


int main()
{
    LinkedList list;

    list.addNode(0);
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    //list.viewFront(list.getHead());
    std::cout << std::endl;
    list.viewReverse(list.getHead());
    std::cout << std::endl << "Count: " << list.count(list.getHead());

    std::cout << std::endl << "\n\n";
    return 0;
}