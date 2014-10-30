#pragma once

namespace linkedlist
{
	class IViewOperations
	{
		public:
			virtual void view() = 0;
			virtual void reverseView() = 0;
	};
}