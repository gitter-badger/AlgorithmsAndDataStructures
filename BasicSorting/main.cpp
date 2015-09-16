#include "Item.h"
#include "ISort.h"
#include "SortMethod.h"
#include "Utils.h"

#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <memory>


int main(int argc, char** argv)
{
    std::vector<Item> items = {
                               Item("Florea", 1),
                               Item("Stefan", 2),
                               Item("Andrei", 3),
                               Item("Oksana", 0),
                               Item("Roli",   4),
                               Item("Butucu", 3),
                               Item("Castor", 5)
                               };

    auto sortingAlgorithm = utils::createSort(SortMethod::OBubble, items);

    utils::viewKeys(sortingAlgorithm->sort());


    std::cout << "\n\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    std::cout << "\n\n";
    return 0;
}