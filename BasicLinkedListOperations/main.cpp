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

    l.swapData(0, 2);
    l.view();


    std::cout << std::endl << "\n\n";
    return 0;
}