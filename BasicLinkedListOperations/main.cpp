#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>


int main()
{
    LinkedList l1;
    l1.addFront(1);
    l1.addFront(2);
    l1.addFront(3);

    LinkedList l2;
    l2.addFront(-1);
    l2.addFront(-2);
    l2.addFront(-3);

    LinkedList result = operations::concatenate(l1, l2);

    result.view();


    std::cout << std::endl << "\n\n";
    return 0;
}