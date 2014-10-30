#pragma once

namespace linkedlist
{
	class IRemoveOperations
	{
		public:
			virtual void removeAfter(int position, int element) = 0;
			virtual void removeBefore(int position, int element) = 0;
			virtual void removeFront(int element) = 0;
			virtual void removeBack(int element) = 0;
	};
}