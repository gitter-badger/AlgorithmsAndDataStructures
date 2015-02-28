#include "CppUnitTest.h"

#include "Utility.h"
#include "../LinkedListFramework/SingleLinkedList_impl1.h"

#include <vector>

using namespace linkedlist::singly::impl1;
using namespace linkedlist::singly;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TestLinkedListFramework
{
TEST_CLASS(SingleLinkedList_impl1)
{
public:
    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(init)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"other")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(init)
    {
        LinkedList<int> list1({1, 2, 3});
        tools::areEqual<int>(list1, {1, 2, 3});
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(length)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"other")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(length)
    {
        int nrElements = 10;
        LinkedList<int> list;
        for(int i = 0; i < nrElements; i++)
        {
            list.addFront(i);
        }

        Assert::IsTrue(list.length() == nrElements);
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(clear)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"other")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(clear)
    {
        LinkedList<int> list;
        list.addFront(1);
        list.addFront(2);
        list.addFront(3);

        list.clear();

        auto flat = list.flatten();
        Assert::IsTrue(flat.empty());
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(addBack)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addBack)
    {
        LinkedList<int> list;
        list.addBack(1);
        list.addBack(2);
        list.addBack(3);

        Assert::IsTrue(tools::areEqual<int>(list, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(addSorted_front)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addSorted_front)
    {
        LinkedList<int> list;
        list.addBack(2);
        list.addBack(4);
        list.addBack(6);

        list.addSorted(0);

        Assert::IsTrue(tools::areEqual<int>(list, {0, 2, 4, 6}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(addSorted_back)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addSorted_back)
    {
        LinkedList<int> list;
        list.addBack(2);
        list.addBack(4);
        list.addBack(6);

        list.addSorted(8);

        Assert::IsTrue(tools::areEqual<int>(list, {2, 4, 6, 8}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(addSorted_middle)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addSorted_middle)
    {
        LinkedList<int> list;
        list.addBack(2);
        list.addBack(4);
        list.addBack(6);
        list.addBack(8);

        list.addSorted(5);

        Assert::IsTrue(tools::areEqual<int>(list, {2, 4, 5, 6, 8}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(addFront)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addFront)
    {
        LinkedList<int> list;
        list.addFront(1);
        list.addFront(2);
        list.addFront(3);

        Assert::IsTrue(tools::areEqual<int>(list, {3, 2, 1}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(remove1stElement)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(remove1stElement)
    {
        LinkedList<int> list({1, 2, 3});
        list.remove(1);

        tools::areEqual<int>(list, {2, 3});
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeLastElement)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeLastElement)
    {
        LinkedList<int> list({1, 2, 3});
        list.remove(3);

        Assert::IsTrue(tools::areEqual<int>(list, {1, 2}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeRandomElement)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeRandomElement)
    {
        LinkedList<int> list({1, 2, 3});
        list.remove(2);

        Assert::IsTrue(tools::areEqual<int>(list, {1, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeNotFoundElement)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeNotFoundElement)
    {
        LinkedList<int> list({1, 2, 3});
        list.remove(4);

        Assert::IsTrue(tools::areEqual<int>(list, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeAll)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeAll)
    {
        LinkedList<int> list({1, 2, 3});
        list.remove(1);
        list.remove(2);
        list.remove(3);

        auto flat = list.flatten();
        Assert::IsTrue(flat.empty());
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeDuplicates_beginning)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeDuplicates_beginning)
    {
        LinkedList<int> list1({1, 1, 1, 2, 3});

        list1.removeDuplicates();
        Assert::IsTrue(tools::areEqual<int>(list1, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeDuplicates_middle)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeDuplicates_middle)
    {
        LinkedList<int> list1({1, 2, 2, 2, 3});

        list1.removeDuplicates();
        Assert::IsTrue(tools::areEqual<int>(list1, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeDuplicates_end)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeDuplicates_end)
    {
        LinkedList<int> list1({1, 2, 3, 3, 3});

        list1.removeDuplicates();
        Assert::IsTrue(tools::areEqual<int>(list1, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(removeDuplicates_noDuplicates)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"remove")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(removeDuplicates_noDuplicates)
    {
        LinkedList<int> list1({1, 2, 3});

        list1.removeDuplicates();
        Assert::IsTrue(tools::areEqual<int>(list1, {1, 2, 3}));
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(loopDetection)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"loop")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(loopDetection)
    {
        Node<int> n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        n6.next = &n7;
        n7.next = &n4;

        LinkedList<int> list(&n1);
        Assert::IsTrue(list.loop() != 0);
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(loopStartDetection)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"loop")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(loopStartDetection)
    {
        Node<int> n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        n6.next = &n7;
        n7.next = &n4;

        LinkedList<int> list(&n1);
        Assert::IsTrue(list.findLoppNode() == &n4);
        Assert::IsFalse(list.findLoppNode() == &n3);
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(loopSizeDetection)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"loop")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(loopSizeDetection)
    {
        Node<int> n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        n6.next = &n7;
        n7.next = &n4;

        LinkedList<int> list(&n1);
        Assert::IsTrue(list.loop() == 4);
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(noLoop)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"loop")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(noLoop)
    {
        LinkedList<int> list1({1, 2, 3});
        Assert::IsTrue(list1.loop() == -1);
    }

    //==============================================================================================================================================
    BEGIN_TEST_METHOD_ATTRIBUTE(singleLoop)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"loop")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(singleLoop)
    {
        Node<int> n1(1);

        n1.next = &n1;

        LinkedList<int> list(&n1);
        Assert::IsTrue(list.loop() == 1);
    }
};
}