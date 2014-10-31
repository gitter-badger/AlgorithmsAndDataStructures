#pragma once

#include "..\LinkedListFramework\SingleLinkedList_impl1.h"

using namespace linkedlist::singly::impl1;


namespace tools
{
	template<typename T>
	bool areEqual(LinkedList<T>& list, const std::vector<T>& vector)
	{
		std::vector<T> flat = list.flatten();

		return flat == vector;
	}
}