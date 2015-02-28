#pragma once

#include "LinkedList.h"


namespace algorithm
{
// circular single linked list operations
bool isCircular(LinkedList& linkedList); // ............................................ tested
int getLoopSize(LinkedList& linkedList); // ............................................ tested
void makeFlat(LinkedList& linkedList); // .............................................. tested
void makeCircular(LinkedList& linkedList); // .......................................... tested

// single operations
void reverseWithSwap(LinkedList& linkedList); // ....................................... tested
void reverseInPlace(LinkedList& linkedList); // ........................................ tested
int getNthToLast(LinkedList& linkedList, int n); // .................................... tested
void getNthToLastRecursive(LinkedList::Node* node, int n, int& result); // ............. tested

// viewing
void viewReverseStack(LinkedList& linkedList);
void viewReverseRecursive(LinkedList::Node* n);

// set operations
LinkedList Union(const LinkedList& l1, const LinkedList& l2); // ....................... tested
LinkedList Difference(const LinkedList& l1, const LinkedList& l2); // .................. tested
LinkedList Intersection(const LinkedList& l1, const LinkedList& l2); // ................ tested

// removal
LinkedList remove(LinkedList& linkedlist, int startPosition, int removeCount); // ...... tested

// swapping
void swapLinks(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);
void swapData(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);
void swapData(LinkedList& linkedList, int pos1, int pos2);

// multiple list operations
LinkedList concatenate(const LinkedList& l1, const LinkedList& l2);
void mergeAlternativeLists(const LinkedList& l1, LinkedList& l2); // ................... tested
LinkedList sum(const LinkedList& l1, const LinkedList& l2); // ......................... tested

// other
int josephus(int n, int m); // tested
void seggregateEvenOdds(LinkedList& linkedList);
void reverseAlternateAndAddAtEnd(LinkedList& linkedList);
void rotateLeft(LinkedList& linkedList, int k);				// tested
void rotateRight(LinkedList& linkedList, int k);			// tested
}