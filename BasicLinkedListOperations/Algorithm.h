#pragma once

#include "LinkedList.h"


//! \namespace algorithm
namespace algorithm
{
//!-----------------------------------------------------------------------------------
//! \fn isCircular
//! \brief     Tests if SLL is circular
//! \param[in] linkedList The list to be tested
//! \returns   True, if the list is circular
//! \throws    no
//!-----------------------------------------------------------------------------------
bool isCircular(const LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief     Returns the loop size of a circular SSL
//! \param[in] linkedList The list to be tested
//! \returns   Size of loop. If not loop detected, returns 0
//! \throws    no
//!-----------------------------------------------------------------------------------
int getLoopSize(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief     Makes a circular SSL flat
//!			   It finds where loop starts using Floyd's algorithm (turtle and hared)
//!			   It then takes that node and makes it point to node->next = nullptr
//! \param[in] linkedList The list to be tested
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void makeFlat(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief   Makes a flat list circular
//!			 It simply takes that tail of the list and makes it point to the head
//! \param[out] linkedList The list to be modified
//! \returns nothing
//! \throws  no
//!-----------------------------------------------------------------------------------
void makeCircular(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief      Reverses a linked list in place using swap
//!				It traverses the list from start and end at the same time and reverses elements
//!				Elements are swapped using std::swap for the internal data
//! \param[out] linkedList The list to be modified
//! \returns    nothing
//! \throws     no
//!-----------------------------------------------------------------------------------
void reverseWithSwap(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief      Reverses the list in place using back pointers
//! \param[out] linkedList List to be modified
//! \returns    nothing
//! \throws     no
//!-----------------------------------------------------------------------------------
void reverseInPlace(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief     Gets nth element to last
//! \param[in] linkedList The SLL
//! \param[in] n		  Nth element from the last
//! \returns   The element in the position n from last
//! \throws    no
//!-----------------------------------------------------------------------------------
int getNthToLast(LinkedList& linkedList, int n);

//!-----------------------------------------------------------------------------------
//! \brief     Same as \c getNthToLast but using recursion
//! \param[in]  node   Node where recursion begins
//! \param[in]  n	   Nth from last
//! \param[out] result The found element
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void getNthToLastRecursive(LinkedList::Node* node, int n, int& result);

//!-----------------------------------------------------------------------------------
//! \brief	   Views a list in reverse
//!			   Practical for lists of any size since it uses a stack internally
//! \param[in] linkedList SLL to be viewed
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void viewReverseStack(const LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief     Views a SLL in reverse using recursion
//!			   Not practical for large lists. It is nice for theory purpose
//! \param[in] n Node where recursion begins
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void viewReverseRecursive(LinkedList::Node* n);

//!-----------------------------------------------------------------------------------
//! \brief     Performs union set operation on 2 lists. Commutative
//! \param[in] l1 SLL 1
//! \param[in] l2 SLL 2
//! \returns   The resulting SLL of the union operation
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList Union(const LinkedList& l1, const LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     Performs Difference set operation on 2 lists. Commutative
//! \param[in] l1 SLL 1
//! \param[in] l2 SLL 2
//! \returns   The resulting SLL of the Difference operation
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList Difference(const LinkedList& l1, const LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     Performs Intersection set operation on 2 lists. Not Commutative
//! \param[in] l1 SLL 1
//! \param[in] l2 SLL 2
//! \returns   The resulting SLL of the Intersection operation
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList Intersection(const LinkedList& l1, const LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     Removes a number of elements starting with a specific position
//! \param[in, out] linkedlist The SLL from where we remove elements. It is not modified
//! \param[in] startPosition Starting position
//! \param[in] removeCount Number of elements to remove
//! \returns   The resulting SLL
//! \throws    out_of_range If startPosition or removeCount do not meet criteria
//!-----------------------------------------------------------------------------------
LinkedList remove(LinkedList& linkedlist, int startPosition, int removeCount);

//!-----------------------------------------------------------------------------------
//! \brief     Swaps 2 nodes inside a list by swapping the links. No practical!
//! \param[in, out] linkedList
//! \param[in] n1
//! \param[in] n2
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void swapLinks(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);

//!-----------------------------------------------------------------------------------
//! \fn swapData
//! \brief     Swaps 2 nodes inside a list by swapping the data of the nodes
//! \param[in, out] linkedList SLL to be modified
//! \param[in] n1 Node 1 to swap
//! \param[in] n2 Node 2 to swap
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void swapData(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2);

//!-----------------------------------------------------------------------------------
//! \brief     Swaps 2 nodes inside a list by swapping the links of the nodes
//!			   Internally uses \c swapLinks
//! \note   L = {0, 1, 2, 3, 4} pos1 = 1, pos2 = 3, => L = {0, 3, 2, 1, 4}
//! \param[in, out] linkedList SLL to be modified
//! \param[in] pos1       Position of the node 1 to swap
//! \param[in] pos2	      Position of the node 2 to swap
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void swapData(LinkedList& linkedList, int pos1, int pos2);

//!-----------------------------------------------------------------------------------
//! \brief     Concatenates 2 SLL by appending first list to second list
//! \note L1 = {0, 1, 2, 3} L2 = {0, 1, 4} => L = {0, 1, 2, 3, 0, 1, 4}
//! \param[in] l1 First SLL
//! \param[in] l2 Second SLL
//! \returns   A SLL representing the concatenated lists
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList concatenate(const LinkedList& l1, const LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     Merges L1 into L2 at alternate position
//! \note   L1={0, 2, 4}, L2={1, 2, 3} => L = {0, 1, 2, 3, 4}
//! \note   L1={0, 2, 4}, L2={1, 2, 3, 5, 7} => L = {0, 1, 2, 3, 4, 5, 7}
//! \param[in]  l1 List to be merged
//! \param[in, out] l2 The resulting merged lists
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void mergeAlternativeLists(const LinkedList& l1, LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     Returns a list representing the sum of 2 lists
//!			   It computes sum of each node from right to left and adds carry
//!	\note   L1 = 1->9 (19), L2 = 2->1->0 (213) => L = 2->3->2 (232)
//! \param[in] l1 First number represented as a list
//! \param[in] l2 Second number represented as a list
//! \returns   The sum of l1 + l2 as a SLL
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList sum(const LinkedList& l1, const LinkedList& l2);

//!-----------------------------------------------------------------------------------
//! \brief     The classical elimination problem
//!			   A number n of people are standing in a circle. Each m person is
//!			   eliminated until there is only one left
//! \param[in] n Number of people in the circle represented as CSLL
//! \param[in] m Remove every mth person
//! \returns   the last remaining person
//! \throws    no
//!-----------------------------------------------------------------------------------
int josephus(int n, int m);

//!-----------------------------------------------------------------------------------
//! \brief     Splits a list in place into odds at beginning, evens at the end
//! \note L = {0, 1, 2, 3, 4, 5, 6} => L = {0, 2, 4, 6, 1, 3, 5}
//! \param[in, out] linkedList SLL to be modified
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void seggregateEvenOdds(LinkedList& linkedList);

//!-----------------------------------------------------------------------------------
//! \brief     Rotates nodes to the left in place
//!			   It quickly converts the SLL->CSLL, makes rotation and convert back SLL
//!	\note   L = {0, 1, 2, 3}, k = 2 => L = {2, 3, 0, 1}
//! \param[in, out] linkedList SLL to be rotated
//! \param[in] k	      How much we rotate the elements
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void rotateLeft(LinkedList& linkedList, int k);

//!-----------------------------------------------------------------------------------
//! \brief     Rotates nodes to the left in place
//!			   It quickly converts the SLL->CSLL, makes rotation and convert back SLL
//! \note	   It uses rotateLeft internally by rotating to left (length - k)
//!	\note   L = {0, 1, 2, 3}, k = 2 => L = {2, 3, 0, 1}
//! \param[out] linkedList SLL to be rotated
//! \param[in]  k	      How much we rotate the elements
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
void rotateRight(LinkedList& linkedList, int k);


bool isPalindrom(const LinkedList& linkedList);

} // namespace algorithm