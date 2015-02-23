#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
int main()
{
    LinkedList l1 = linkedlist::createFromNumber(563);
    LinkedList l2 = linkedlist::createFromNumber(842);
    LinkedList l3 = linkedlist::sum(l1, l2);

    l1.view();
    std::cout << " + ";
    l2.view();
    std::cout << " = ";
    l3.view();

    std::cout << std::endl << "\n\n";
    return 0;
}