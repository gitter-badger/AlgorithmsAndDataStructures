#pragma once

#include "LinkedList.h"


namespace algorithm
{
	// circular single linked list operations
	bool isCircular(LinkedList& linkedList);
	int getLoopSize(LinkedList& linkedList);
	void makeFlat(LinkedList& linkedList);
	void makeCircular(LinkedList& linkedList);

	// single operations
	void reverseWithSwap(LinkedList& linkedList);
	void reverseInPlace(LinkedList& linkedList);
	int getNthToLast(LinkedList& linkedList, int n);
	void getNthToLastRecursive(LinkedList::Node* node, int n, int& result);

	// viewing
	void viewReverseStack(LinkedList& linkedList);
	void viewReverseRecursive(LinkedList::Node* n);

	// swapping
	void swapLinks(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);
	void swapData(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);

	// multiple list operations
	LinkedList concatenate(const LinkedList& l1, const LinkedList& l2);
	void mergeAlternativeLists(const LinkedList& l1, LinkedList& l2);
	LinkedList sum(const LinkedList& l1, const LinkedList& l2);

	// other
	int josephus(int n, int m);
}