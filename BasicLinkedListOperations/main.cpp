#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
int main()
{
    LinkedList l;
    for(int i = 0; i < 2; i++)
    {
        l.insert(i);
    }

    std::cout << std::endl << std::setw(15) << std::setfill('-') << "\n";
    l.view();

    l.reverseInPlace();
    std::cout << std::endl << std::setw(15) << std::setfill('-') << "\n";
    l.view();

    std::cout << std::endl << "\n\n";
    return 0;
}