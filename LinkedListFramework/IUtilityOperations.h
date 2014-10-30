#pragma once

#include <vector>

namespace linkedlist
{
	class IUtilityOperations
	{
		public:
			virtual void sort()              = 0;
			virtual int length()             = 0;
			virtual void reverse()           = 0;
			virtual bool search(int element) = 0;
			virtual void removeDuplicates()  = 0;
	};
}