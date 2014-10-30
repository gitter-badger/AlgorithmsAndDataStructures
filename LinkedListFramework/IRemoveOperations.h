#pragma once

namespace linkedlist
{
	class IRemoveOperations
	{
		public:
			virtual void removeAfter(int position)  = 0;
			virtual void removeBefore(int position) = 0;
			virtual void removeFront()              = 0;
			virtual void removeBack()               = 0;
			virtual void remove(int element)	    = 0;
	};
}