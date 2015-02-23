#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
int main()
{
    LinkedList l;
    for(int i = 0; i < 8; i++)
    {
        l.insert(i);
    }

    l.view();
    int result;
    l.getNthToLastRecursive(l.getHead(), 3, result);
    std::cout << std::endl << result;

    std::cout << std::endl << "\n\n";
    return 0;
}