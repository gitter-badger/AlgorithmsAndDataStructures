#include "Item.h"
#include "ISort.h"
#include "SortMethod.h"
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

    auto sortMethod = utils::createSort(SortMethod::Bubble, items);

    auto sorted = sortMethod->sort();

    std::cout << "Is sorted: " << utils::isSorted(sorted) << "\n";
    utils::viewData(sorted);


    std::cout << "\n\n";
    return 0;
}