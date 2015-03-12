#include "Utils.h"

#include "../BasicLinkedListOperations/Factory.h"
#include "../BasicLinkedListOperations/Algorithm.h"
#include "../BasicLinkedListOperations/Exceptions.h"

#include <gtest/gtest.h>


//==============================================================================================================================================
TEST(LinkedListAlgorithms, Rotate)
{
    auto list = factory::create({0, 1, 2, 3});

    algorithm::rotateLeft(list, 1);
    EXPECT_TRUE(utils::areEqual(list, {1, 2, 3, 0}));

    algorithm::rotateRight(list, 1);
    EXPECT_TRUE(utils::areEqual(list, {0, 1, 2, 3}));

    algorithm::rotateRight(list, 4);
    EXPECT_TRUE(utils::areEqual(list, {0, 1, 2, 3}));

    algorithm::rotateLeft(list, 4);
    EXPECT_TRUE(utils::areEqual(list, {0, 1, 2, 3}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, SetOperations)
{
    auto set1 = factory::create({0, 1, 2, 3});
    auto set2 = factory::create({4, 1, 2, 5});

    auto unionSet1 = algorithm::Union(set1, set2);
    EXPECT_TRUE(utils::isContained(unionSet1, {0, 1, 2, 3, 4, 5}));

    auto unionSet2 = algorithm::Union(set2, set1);
    EXPECT_TRUE(utils::isContained(unionSet2, {0, 1, 2, 3, 4, 5}));

    auto intersectionSet1 = algorithm::Intersection(set1, set2);
    EXPECT_TRUE(utils::isContained(intersectionSet1, {1, 2}));

    auto intersectionSet2 = algorithm::Intersection(set2, set1);
    EXPECT_TRUE(utils::isContained(intersectionSet2, {1, 2}));

    auto differenceSet1 = algorithm::Difference(set1, set2);
    EXPECT_TRUE(utils::isContained(differenceSet1, {0, 3}));

    auto differenceSet2 = algorithm::Difference(set2, set1);
    EXPECT_TRUE(utils::isContained(differenceSet2, {5, 4}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Sum)
{
    __int64 n1 = 9999;
    __int64 n2 = 999999999;
    LinkedList resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
    EXPECT_EQ(utils::convertToString(resultSum), std::to_string(n1 + n2));

    n1 = 123;
    n2 = 222;
    resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
    EXPECT_EQ(utils::convertToString(resultSum), std::to_string(n1 + n2));

    n1 = 1;
    n2 = 11;
    resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
    EXPECT_EQ(utils::convertToString(resultSum), std::to_string(n1 + n2));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, RemoveNAfterM)
{
    auto list = factory::create({0, 1, 2, 3, 4});

    EXPECT_TRUE(utils::areEqual(algorithm::remove(list, 1, 1), {0, 2, 3, 4}));
    EXPECT_TRUE(utils::areEqual(algorithm::remove(list, 1, 2), {0, 3, 4}));
    EXPECT_TRUE(utils::areEqual(algorithm::remove(list, 1, 4), {0}));
    EXPECT_TRUE(utils::areEqual(algorithm::remove(list, 0, 2), {2, 3, 4}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Clone)
{
    auto list = factory::create({2, 3, 4, 1});
    auto cloned = factory::create(list);

    utils::areEqual(list, cloned);
    utils::areEqual(list, list);
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Swap)
{
    auto list = factory::create({0, 1, 2, 3, 4});
    algorithm::swapData(list, 2, 4);
    EXPECT_TRUE(utils::areEqual(list, {0, 1, 4, 3, 2}));

    list = factory::create({0, 1, 2, 3, 4});
    algorithm::swapLinks(list, list.getNth(2), list.getNth(4));
    EXPECT_TRUE(utils::areEqual(list, {0, 1, 4, 3, 2}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Reverse)
{
    auto list = factory::create({0, 1, 2, 3, 4});
    algorithm::reverseInPlace(list);
    EXPECT_TRUE(utils::areEqual(list, {4, 3, 2, 1, 0}));

    list = factory::create({0, 1, 2, 3, 4});
    algorithm::reverseWithSwap(list);
    EXPECT_TRUE(utils::areEqual(list, {4, 3, 2, 1, 0}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Circular)
{
    LinkedList::Node* n1 = new LinkedList::Node(1);
    LinkedList::Node* n2 = new LinkedList::Node(1);
    LinkedList::Node* n3 = new LinkedList::Node(1);
    LinkedList::Node* n4 = new LinkedList::Node(1);
    LinkedList circularList(n1); // now becomes the owned of head = n1. No memory leak

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n3; // loop size = 2

    EXPECT_TRUE(algorithm::isCircular(circularList));
    EXPECT_EQ(algorithm::getLoopSize(circularList), 2);

    algorithm::makeFlat(circularList);
    EXPECT_FALSE(algorithm::isCircular(circularList));
    EXPECT_EQ(algorithm::getLoopSize(circularList), 0);

    algorithm::makeCircular(circularList);
    EXPECT_TRUE(algorithm::isCircular(circularList));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, MergeAlternatePositions)
{
    auto list1 = factory::create({2, 4, 6});
    auto list2 = factory::create({1, 3, 5});
    algorithm::mergeAlternativeLists(list1, list2); // for efficiency reasons, list1 is merged into list2
    EXPECT_TRUE(utils::areEqual(list2, {1, 2, 3, 4, 5, 6}));

    list1 = factory::create({2, 4, 6});
    list2 = factory::create({1, 3, 5, 7, 9, 11});
    algorithm::mergeAlternativeLists(list1, list2);
    EXPECT_TRUE(utils::areEqual(list2, {1, 2, 3, 4, 5, 6, 7, 9, 11}));

    list1 = factory::create({2, 4, 6, 8, 10});
    list2 = factory::create({1, 3, 5});
    algorithm::mergeAlternativeLists(list1, list2);
    EXPECT_TRUE(utils::areEqual(list2, {1, 2, 3, 4, 5, 6, 8, 10}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, GetNth)
{
    auto list = factory::create({0, 1, 2, 3, 4});

    EXPECT_EQ(algorithm::getNthToLast(list, 2), 3);
    EXPECT_EQ(algorithm::getNthToLast(list, 1), 4);
    EXPECT_EQ(algorithm::getNthToLast(list, 5), 0);

    int result = -1;
    algorithm::getNthToLastRecursive(list.getHead(), 2, result);
    EXPECT_EQ(result, 3);

    algorithm::getNthToLastRecursive(list.getHead(), 1, result);
    EXPECT_EQ(result, 4);

    algorithm::getNthToLastRecursive(list.getHead(), 5, result);
    EXPECT_EQ(result, 0);
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Insertion)
{
    LinkedList l1;
    l1.addFront(1);
    l1.addFront(2);
    l1.addFront(3);
    EXPECT_TRUE(utils::areEqual(l1, {3, 2, 1}));

    LinkedList l2;
    l2.addBack(1);
    l2.addBack(2);
    l2.addBack(3);
    EXPECT_TRUE(utils::areEqual(l2, {1, 2, 3}));

    LinkedList l3;
    l3.insert(0);
    l3.insert(1);
    l3.insert(3);
    l3.insert(2);
    l3.insert(4);
    EXPECT_TRUE(utils::areEqual(l3, {0, 1, 2, 3, 4}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Removal)
{
    auto list = factory::create({0, 1, 2, 3, 4});
    list.removeFront();
    EXPECT_TRUE(utils::areEqual(list, {1, 2, 3, 4}));

    list.removeBack();
    EXPECT_TRUE(utils::areEqual(list, {1, 2, 3}));

    auto sorted = factory::create({0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6, 6});
    sorted.removeDuplicates();
    EXPECT_TRUE(utils::areEqual(sorted, {0, 1, 2, 3, 4, 5, 6}));

    auto l = factory::create({0, 1, 2, 3, 4, 5});
    l.remove(1);
    EXPECT_TRUE(utils::areEqual(l, {1, 2, 3, 4, 5}));

    l = factory::create({0, 1, 2, 3, 4, 5});
    l.remove(3);
    EXPECT_TRUE(utils::areEqual(l, {0, 1, 2, 4, 5}));

    l = factory::create({0, 1, 2, 3, 4, 5});
    l.remove(5);
    EXPECT_TRUE(utils::areEqual(l, {0, 1, 2, 3, 4}));

    l.clearAll();
    EXPECT_TRUE(utils::areEqual(l, {}));
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Getters)
{
    auto list = factory::create({0, 1, 2, 3, 4, 5, 6});

    EXPECT_EQ(list.getLenght(), 7);
    EXPECT_EQ(list.getFront(), 0);

    EXPECT_EQ(list.getNth(2)->data, 2);
    EXPECT_EQ(list.getNth(0)->data, 0);
    EXPECT_EQ(list.getNth(6)->data, 6);

    EXPECT_EQ(list.getMiddle(), 3);

    EXPECT_EQ(list.getPosition(list.getHead()), 0);
}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Conversion)
{
    auto list = factory::create({0, 1, 2});
    std::vector<int> elements = list;

    LinkedList::Node* n = list.getHead();
    auto it = elements.begin();

    EXPECT_EQ(static_cast<int>(elements.size()), list.getLenght());

    while(n)
    {
        EXPECT_EQ(*it, n->data);
        n = n->next;
        it++;
    }

}

//==============================================================================================================================================
TEST(LinkedListAlgorithms, Exceptions)
{
    auto f1 = []()
    {
        LinkedList emptyList;
        emptyList.removeFront();
    };
    EXPECT_THROW(f1(), exceptions::empty_list);

    auto f2 = []()
    {
        LinkedList list = factory::create({0, 1, 2, 3});
        list.remove(5);
    };
    EXPECT_THROW(f2(), exceptions::out_of_range);
}
