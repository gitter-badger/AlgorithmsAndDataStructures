#pragma once

namespace linkedlist
{
	class IInsertOperations
	{
		public:
			virtual void insertAfter(int position, int element)  = 0;
			virtual void insertBefore(int position, int element) = 0;
			virtual void insertFront(int element)                = 0;
			virtual void insertBack(int element)                 = 0;
			virtual void insertSorted(int element)               = 0;
	};
}