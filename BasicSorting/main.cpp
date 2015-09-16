#include "Item.h"
#include "ISort.h"
#include "SortMethod.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <memory>


int main()
{
    std::vector<Item> before;
    std::vector<Item> after;

    Item item1("Florea", 1);
    Item item2("Andrei", 2);
    Item item3("Oksana", 1);
    Item item4("Tudor",  3);
    Item item5("Stefan", 3);

    before.push_back(item1);
    before.push_back(item2);
    before.push_back(item3);
    before.push_back(item4);
    before.push_back(item5);

    after.push_back(item1);
    after.push_back(item3);
    after.push_back(item2);
    after.push_back(item4);
    after.push_back(item5);


    utils::viewData(before);
    std::cout << "\n\nIs stable: " << utils::isStable(before, after) << "\n";
    utils::viewData(after);

    std::cout << "\n\n";
    return 0;
}