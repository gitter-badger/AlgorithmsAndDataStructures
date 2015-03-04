#include "CppUnitTest.h"

#include "Utility.h"
#include "../LinkedListFramework/DoublyLinkedList_impl1.h"

//using namespace linkedlist::doubly::impl1;
//using namespace linkedlist::doubly;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestLinkedListFramework
{
TEST_CLASS(Test_DoublyLinkedList_impl2)
{
public:

    BEGIN_TEST_METHOD_ATTRIBUTE(addFront)
    TEST_METHOD_ATTRIBUTE(L"functionality", L"add")
    TEST_METHOD_ATTRIBUTE(L"implementation", L"impl1")
    TEST_METHOD_ATTRIBUTE(L"type", L"doubly")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(addFront)
    {
        linkedlist::doubly::impl1::LinkedList<int> list;
        list.addFront(1);
        list.addFront(2);
        list.addFront(3);

        //Assert::IsTrue(tools::areEqual<int>(list, {3, 2, 1}));
    }
};
}