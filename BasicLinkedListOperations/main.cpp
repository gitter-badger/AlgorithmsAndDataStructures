#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
int main()
{
    LinkedList l;
    l.insert(0);
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);

    l.swap(0, 3);

    std::cout << std::endl << std::setw(15) << std::setfill('-') << "\n";
    l.view();


    std::cout << std::endl << "\n\n";
    return 0;
}