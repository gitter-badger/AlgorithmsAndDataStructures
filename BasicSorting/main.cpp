#include "Item.h"
#include "ISort.h"
#include "BubbleSort.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <memory>


int main()
{
    std::vector<Item> items;
    items.emplace_back("Florea", 1);
    items.emplace_back("Stefan", 2);
    items.emplace_back("Andrei", 3);
    items.emplace_back("Oksana", 4);
    items.emplace_back("Igor",   5);

    std::cout << "Is sorted: " << utils::isSorted(items) << "\n";



    return 0;
}