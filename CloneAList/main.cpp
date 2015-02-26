#include "Node.h"
#include "Algorithm.h"

#include <iostream>
#include <assert.h>


int main()
{
    Node* list = factory::createRandPrevList();

    Node* clonedList = algorithm::Clone(list);

    algorithm::ViewPrev(list);
    std::cout << std::endl;
    algorithm::ViewPrev(clonedList);


    std::cout << "\n" << "\n";
    return 0;
}