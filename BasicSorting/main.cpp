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
    items.emplace_back("Stefan", 3);
    items.emplace_back("Andrei", 2);
    items.emplace_back("Oksana", 5);
    items.emplace_back("Igor",   8);

    std::cout << "Is sorted: " << utils::isSorted(items) << "\n";
    utils::viewData(items);


    std::cout << "\n\n";
    return 0;
}