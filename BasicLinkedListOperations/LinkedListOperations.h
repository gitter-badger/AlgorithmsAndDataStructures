#pragma once

#include "LinkedList.h"


namespace linkedlist
{

LinkedList concatenate(const LinkedList& l1, const LinkedList& l2);

int josephus(int n, int m);

void mergeAlternativeLists(const LinkedList& l1, LinkedList& l2);

LinkedList sum(const LinkedList& l1, const LinkedList& l2);

LinkedList createFromNumber(__int64 n);

}