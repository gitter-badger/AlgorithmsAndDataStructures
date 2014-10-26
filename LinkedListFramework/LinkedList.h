#pragma once

namespace linkedlist
{
	class LinkedList
	{
		public:
			virtual void view() {}
			virtual void reverseView() {}

			virtual void insertAfter(int position, int element) {}
			virtual void insertBefore(int position, int element) {}
			virtual void insertFront(int element) {}
			virtual void insertBack(int element) {}
			virtual void insertSorted(int element) {}

			virtual void removeAfter(int position, int element) {}
			virtual void removeBefore(int position, int element) {}
			virtual void removeFront(int element) {}
			virtual void removeBack(int element) {}

			virtual void sort() {}
			virtual int length() { return -1; }
			virtual void reverse() {}
			virtual bool search(int element) { return false; }

			virtual void append(const LinkedList& list) {}
			virtual void sortedMerge(const LinkedList& list) {}
			virtual void removeDuplicates() {}
	};
}