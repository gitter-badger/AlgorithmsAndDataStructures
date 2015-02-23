#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
int main()
{
    __int64 n1 = 9999;
    __int64 n2 = 999999999;
    LinkedList l1 = linkedlist::createFromNumber(n1);
    LinkedList l2 = linkedlist::createFromNumber(n2);
    LinkedList l3 = linkedlist::sum(l1, l2);

    std::cout << "list: ";
    l1.view();
    std::cout << " + ";
    l2.view();
    std::cout << " = ";
    l3.view();

    std::cout << "\nmath: ";
    std::cout << n1 << " + " << n2 << " = " << n1 + n2;

    std::cout << std::endl << "\n\n";
    return 0;
}