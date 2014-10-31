#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\LinkedListFramework\SingleLinkedList_impl1.h"

#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace linkedlist::singly::impl1;

namespace TestLinkedListFramework
{		
	TEST_CLASS(SingleLinkedList_impl1)
	{
		public:
			TEST_METHOD(init)
			{
				LinkedList<int> list1({1, 2, 3});
				areEqual<int>(list1, {1, 2, 3});
			}

			TEST_METHOD(addFront)
			{
				LinkedList<int> list;
				list.addFront(1);
				list.addFront(2);
				list.addFront(3);

				Assert::IsTrue(areEqual<int>(list, {3, 2, 1}));
			}

			TEST_METHOD(length)
			{
				int nrElements = 10;
				LinkedList<int> list;
				for(int i = 0; i < nrElements; i++)
					list.addFront(i);

				Assert::IsTrue(list.length() == nrElements);
			}

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

			TEST_METHOD(addBack)
			{
				LinkedList<int> list;
				list.addBack(1);
				list.addBack(2);
				list.addBack(3);

				Assert::IsTrue(areEqual<int>(list, {1, 2, 3}));
			}

			TEST_METHOD(remove1stElement)
			{
				LinkedList<int> list({1, 2, 3});
				list.remove(1);

				areEqual<int>(list, {2, 3});
			}

			TEST_METHOD(removeLastElement)
			{
				LinkedList<int> list({1, 2, 3});
				list.remove(3);

				areEqual<int>(list, {1, 2});
			}

			TEST_METHOD(removeRandomElement)
			{
				LinkedList<int> list({1, 2, 3});
				list.remove(2);

				areEqual<int>(list, {1, 3});
			}

			TEST_METHOD(removeNotFoundElement)
			{
				LinkedList<int> list({1, 2, 3});
				list.remove(4);

				areEqual<int>(list, {1, 2, 3});
			}

			TEST_METHOD(removeAll)
			{
				LinkedList<int> list({1, 2, 3});
				list.remove(1);
				list.remove(2);
				list.remove(3);

				auto flat = list.flatten();
				Assert::IsTrue(flat.empty());
			}

		private:
			template<typename T>
			bool areEqual(LinkedList<T>& list, const std::vector<T>& vector)
			{
				std::vector<T> flat = list.flatten();

				return flat == vector;
			}
	};
}