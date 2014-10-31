#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\LinkedListFramework\SingleLinkedList.h"

#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLinkedListFramework
{		
	TEST_CLASS(BasicOperations)
	{
		public:
			TEST_METHOD(init)
			{
				linkedlist::SingleLinkedList<int> list1({1,2,3});
				areEqual<int>(list1, {1, 2, 3});
			}

			TEST_METHOD(addFront)
			{
				linkedlist::SingleLinkedList<int> list;
				list.addFront(1);
				list.addFront(2);
				list.addFront(3);

				Assert::IsTrue(areEqual<int>(list, {3, 2, 1}));
			}

			TEST_METHOD(length)
			{
				int nrElements = 10;
				linkedlist::SingleLinkedList<int> list;
				for (int i = 0; i < nrElements ; i++)
					list.addFront(i);

				Assert::IsTrue(list.length() == nrElements);
			}

			TEST_METHOD(clear)
			{
				linkedlist::SingleLinkedList<int> list;
				list.addFront(1);
				list.addFront(2);
				list.addFront(3);

				list.clear();

				auto flat = list.flatten();
				Assert::IsTrue(flat.empty());
			}

			TEST_METHOD(addBack)
			{
				linkedlist::SingleLinkedList<int> list;
				list.addBack(1);
				list.addBack(2);
				list.addBack(3);

				Assert::IsTrue(areEqual<int>(list, {1, 2, 3}));
			}

			TEST_METHOD(remove1stElement)
			{
				linkedlist::SingleLinkedList<int> list({1, 2, 3});
				list.remove(1);

				areEqual<int>(list, {2,3});
			}

			TEST_METHOD(removeLastElement)
			{
				linkedlist::SingleLinkedList<int> list({1, 2, 3});
				list.remove(3);

				areEqual<int>(list, {1, 2});
			}

			TEST_METHOD(removeRandomElement)
			{
				linkedlist::SingleLinkedList<int> list({1, 2, 3});
				list.remove(2);

				areEqual<int>(list, {1, 3});
			}

			TEST_METHOD(removeNotFoundElement)
			{
				linkedlist::SingleLinkedList<int> list({1, 2, 3});
				list.remove(4);

				areEqual<int>(list, {1, 2, 3});
			}

			TEST_METHOD(removeAll)
			{
				linkedlist::SingleLinkedList<int> list({1, 2, 3});
				list.remove(1);
				list.remove(2);
				list.remove(3);

				auto flat = list.flatten();
				Assert::IsTrue(flat.empty());
			}

		private:
			template<typename T>
			bool areEqual(linkedlist::SingleLinkedList<T>& list, const std::vector<T>& vector)
			{
				std::vector<T> flat = list.flatten();

				return flat == vector;
			}
	};
}