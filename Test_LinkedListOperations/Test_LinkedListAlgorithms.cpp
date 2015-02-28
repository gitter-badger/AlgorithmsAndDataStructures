#include "CppUnitTest.h"

#include "Utils.h"

#include "../BasicLinkedListOperations/Factory.h"
#include "../BasicLinkedListOperations/Algorithm.h"
#include "../BasicLinkedListOperations/Exceptions.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Test_LinkedListOperations
{

TEST_CLASS(LinkedListAlgorithms)
{
public:

    //==============================================================================================================================================
    TEST_METHOD(Rotate)
    {
        auto list = factory::create({0, 1, 2, 3});

        algorithm::rotateLeft(list, 1);
        Assert::IsTrue(utils::areEqual(list, {1, 2, 3, 0}));

        algorithm::rotateRight(list, 1);
        Assert::IsTrue(utils::areEqual(list, {0, 1, 2, 3}));

        algorithm::rotateRight(list, 4);
        Assert::IsTrue(utils::areEqual(list, {0, 1, 2, 3}));

        algorithm::rotateLeft(list, 4);
        Assert::IsTrue(utils::areEqual(list, {0, 1, 2, 3}));
    }

    //==============================================================================================================================================
    TEST_METHOD(SetOperations)
    {
        auto set1 = factory::create({0, 1, 2, 3});
        auto set2 = factory::create({4, 1, 2, 5});

        auto unionSet1 = algorithm::Union(set1, set2);
        Assert::IsTrue(utils::isContained(unionSet1, {0, 1, 2, 3, 4, 5}));

        auto unionSet2 = algorithm::Union(set2, set1);
        Assert::IsTrue(utils::isContained(unionSet2, {0, 1, 2, 3, 4, 5}));

        auto intersectionSet1 = algorithm::Intersection(set1, set2);
        Assert::IsTrue(utils::isContained(intersectionSet1, {1, 2}));

        auto intersectionSet2 = algorithm::Intersection(set2, set1);
        Assert::IsTrue(utils::isContained(intersectionSet2, {1, 2}));

        auto differenceSet1 = algorithm::Difference(set1, set2);
        Assert::IsTrue(utils::isContained(differenceSet1, {0, 3}));

        auto differenceSet2 = algorithm::Difference(set2, set1);
        Assert::IsTrue(utils::isContained(differenceSet2, {5, 4}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Sum)
    {
        __int64 n1 = 9999;
        __int64 n2 = 999999999;
        LinkedList resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
        Assert::AreEqual(utils::convertToString(resultSum), std::to_string(n1 + n2));

        n1 = 123;
        n2 = 222;
        resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
        Assert::AreEqual(utils::convertToString(resultSum), std::to_string(n1 + n2));

        n1 = 1;
        n2 = 11;
        resultSum = algorithm::sum(factory::create(n1), factory::create(n2));
        Assert::AreEqual(utils::convertToString(resultSum), std::to_string(n1 + n2));
    }

    //==============================================================================================================================================
    TEST_METHOD(RemoveNAfterM)
    {
        auto list = factory::create({0, 1, 2, 3, 4});

        Assert::IsTrue(utils::areEqual(algorithm::remove(list, 1, 1), {0, 2, 3, 4}));
        Assert::IsTrue(utils::areEqual(algorithm::remove(list, 1, 2), {0, 3, 4}));
        Assert::IsTrue(utils::areEqual(algorithm::remove(list, 1, 4), {0}));
        Assert::IsTrue(utils::areEqual(algorithm::remove(list, 0, 2), {2, 3, 4}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Clone)
    {
        auto list   = factory::create({2, 3, 4, 1});
        auto cloned = factory::create(list);

        utils::areEqual(list, cloned);
        utils::areEqual(list, list);
    }

    //==============================================================================================================================================
    TEST_METHOD(Swap)
    {
        auto list = factory::create({0, 1, 2, 3, 4});
        algorithm::swapData(list, 2, 4);
        Assert::IsTrue(utils::areEqual(list, {0, 1, 4, 3, 2}));

        list = factory::create({0, 1, 2, 3, 4});
        algorithm::swapLinks(list, list.getNth(2), list.getNth(4));
        Assert::IsTrue(utils::areEqual(list, {0, 1, 4, 3, 2}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Reverse)
    {
        auto list = factory::create({0, 1, 2, 3, 4});
        algorithm::reverseInPlace(list);
        Assert::IsTrue(utils::areEqual(list, {4, 3, 2, 1, 0}));

        list = factory::create({0, 1, 2, 3, 4});
        algorithm::reverseWithSwap(list);
        Assert::IsTrue(utils::areEqual(list, {4, 3, 2, 1, 0}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Circular)
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

        Assert::IsTrue(algorithm::isCircular(circularList));
        Assert::AreEqual(algorithm::getLoopSize(circularList), 2);

        algorithm::makeFlat(circularList);
        Assert::IsFalse(algorithm::isCircular(circularList));
        Assert::AreEqual(algorithm::getLoopSize(circularList), 0);

        algorithm::makeCircular(circularList);
        Assert::IsTrue(algorithm::isCircular(circularList));
    }

    //==============================================================================================================================================
    TEST_METHOD(MergeAlternatePositions)
    {
        auto list1 = factory::create({2, 4, 6});
        auto list2 = factory::create({1, 3, 5});
        algorithm::mergeAlternativeLists(list1, list2); // for efficiency reasons, list1 is merged into list2
        Assert::IsTrue(utils::areEqual(list2, {1, 2, 3, 4, 5 , 6}));

        list1 = factory::create({2, 4, 6});
        list2 = factory::create({1, 3, 5, 7, 9, 11});
        algorithm::mergeAlternativeLists(list1, list2);
        Assert::IsTrue(utils::areEqual(list2, {1, 2, 3, 4, 5, 6, 7, 9, 11}));

        list1 = factory::create({2, 4, 6, 8, 10});
        list2 = factory::create({1, 3, 5});
        algorithm::mergeAlternativeLists(list1, list2);
        Assert::IsTrue(utils::areEqual(list2, {1, 2, 3, 4, 5, 6, 8, 10}));
    }

    //==============================================================================================================================================
    TEST_METHOD(GetNth)
    {
        auto list = factory::create({0, 1, 2, 3, 4});

        Assert::AreEqual(algorithm::getNthToLast(list, 2), 3);
        Assert::AreEqual(algorithm::getNthToLast(list, 1), 4);
        Assert::AreEqual(algorithm::getNthToLast(list, 5), 0);

        int result = -1;
        algorithm::getNthToLastRecursive(list.getHead(), 2, result);
        Assert::AreEqual(result, 3);

        algorithm::getNthToLastRecursive(list.getHead(), 1, result);
        Assert::AreEqual(result, 4);

        algorithm::getNthToLastRecursive(list.getHead(), 5, result);
        Assert::AreEqual(result, 0);
    }

    //==============================================================================================================================================
    TEST_METHOD(Insertion)
    {
        LinkedList l1;
        l1.addFront(1);
        l1.addFront(2);
        l1.addFront(3);
        Assert::IsTrue(utils::areEqual(l1, {3, 2, 1}));

        LinkedList l2;
        l2.addBack(1);
        l2.addBack(2);
        l2.addBack(3);
        Assert::IsTrue(utils::areEqual(l2, {1, 2, 3}));

        LinkedList l3;
        l3.insert(0);
        l3.insert(1);
        l3.insert(3);
        l3.insert(2);
        l3.insert(4);
        Assert::IsTrue(utils::areEqual(l3, {0, 1, 2, 3, 4}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Removal)
    {
        auto list = factory::create({0, 1, 2, 3, 4});
        list.removeFront();
        Assert::IsTrue(utils::areEqual(list, {1, 2, 3, 4}));

        list.removeBack();
        Assert::IsTrue(utils::areEqual(list, {1, 2, 3}));

        auto sorted = factory::create({0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6, 6});
        sorted.removeDuplicates();
        Assert::IsTrue(utils::areEqual(sorted, {0, 1, 2, 3, 4, 5, 6}));

        auto l = factory::create({0, 1, 2, 3, 4, 5});
        l.remove(1);
        Assert::IsTrue(utils::areEqual(l, {1, 2, 3, 4, 5}));

        l = factory::create({0, 1, 2, 3, 4, 5});
        l.remove(3);
        Assert::IsTrue(utils::areEqual(l, {0, 1, 2, 4, 5}));

        l = factory::create({0, 1, 2, 3, 4, 5});
        l.remove(5);
        Assert::IsTrue(utils::areEqual(l, {0, 1, 2, 3, 4}));

        l.clearAll();
        Assert::IsTrue(utils::areEqual(l, {}));
    }

    //==============================================================================================================================================
    TEST_METHOD(Getters)
    {
        auto list = factory::create({0, 1, 2, 3, 4, 5, 6});

        Assert::AreEqual(list.getLenght(), 7);
        Assert::AreEqual(list.getFront(), 0);

        Assert::AreEqual(list.getNth(2)->data, 2);
        Assert::AreEqual(list.getNth(0)->data, 0);
        Assert::AreEqual(list.getNth(6)->data, 6);

        Assert::AreEqual(list.getMiddle(), 3);

        Assert::AreEqual(list.getPosition(list.getHead()), 0);
    }

    //==============================================================================================================================================
    TEST_METHOD(Conversion)
    {
        auto list = factory::create({0, 1, 2});
        std::vector<int> elements = list;

        LinkedList::Node* n = list.getHead();
        auto it = elements.begin();

        Assert::AreEqual(static_cast<int>(elements.size()), list.getLenght());

        while(n)
        {
            Assert::AreEqual(*it, n->data);
            n = n->next;
            it++;
        }

    }

    //==============================================================================================================================================
    TEST_METHOD(Exceptions)
    {
        Assert::ExpectException<exceptions::empty_list>([]()
        {
            LinkedList emptyList;
            emptyList.removeFront();
        });

        Assert::ExpectException<exceptions::empty_list>([]()
        {
            LinkedList emptyList;
            emptyList.removeBack();
        });

        Assert::ExpectException<exceptions::out_of_range>([]()
        {
            LinkedList list = factory::create({0, 1, 2, 3});
            list.remove(-1);
        });

        Assert::ExpectException<exceptions::out_of_range>([]()
        {
            LinkedList list = factory::create({0, 1, 2, 3});
            list.remove(5);
        });

        Assert::ExpectException<exceptions::out_of_range>([]()
        {
            LinkedList list = factory::create({0, 1, 2, 3});
            list.getNth(10);
        });
    }

private:
    void viewList(LinkedList & list)
    {
        std::vector<int> elements = list;
        std::stringstream stream;
        for(auto e : elements)
        {
            stream << " " << std::to_string(e);
        }

        Logger::WriteMessage(stream.str().c_str());
    }
};

}
