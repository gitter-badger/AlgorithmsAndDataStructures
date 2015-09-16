#include "Item.h"
#include "Utils.h"

#include <gtest/gtest.h>

#include <vector>


//----------------------------------------------------------------------------------------------------------------------------------------------
TEST(utils, isStable)
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

    EXPECT_TRUE(utils::isStable(before, after));
}

//----------------------------------------------------------------------------------------------------------------------------------------------
TEST(utils, isNotStable)
{
    std::vector<Item> before;
    std::vector<Item> after;

    Item item1("Florea", 1);
    Item item2("Andrei", 2);
    Item item3("Oksana", 1);
    Item item4("Tudor", 3);
    Item item5("Stefan", 3);

    before.push_back(item1);
    before.push_back(item2);
    before.push_back(item3);
    before.push_back(item4);
    before.push_back(item5);

    after.push_back(item1);
    after.push_back(item3);
    after.push_back(item2);
    after.push_back(item5);
    after.push_back(item4);

    EXPECT_FALSE(utils::isStable(before, after));
}

//----------------------------------------------------------------------------------------------------------------------------------------------
TEST(utils, isSorted)
{
    std::vector<Item> sorted = {Item("A", 1), Item("B", 2), Item("C", 3), Item("D", 4)};
    EXPECT_TRUE(utils::isSorted(sorted));

    std::vector<Item> notSorted = {Item("A", 2), Item("B", 1), Item("C", 3), Item("D", 4)};
    EXPECT_FALSE(utils::isSorted(notSorted));
}
