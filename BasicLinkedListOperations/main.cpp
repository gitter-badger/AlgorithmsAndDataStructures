#include "LinkedList.h"
#include "LinkedListOperations.h"

#include <iostream>


int main()
{
    std::cout << std::endl << operations::josephus(9, 5);
    std::cout << std::endl << "\n\n";
    return 0;
}