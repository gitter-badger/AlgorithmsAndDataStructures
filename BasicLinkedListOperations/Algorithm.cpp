#include "Algorithm.h"

#include <iostream>
#include <stack>
#include <assert.h>

#define recursive


namespace algorithm
{

//=============================================================================
bool isCircular(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();
	bool circular = false;

	LinkedList::Node* fast = head;
	LinkedList::Node* slow = head;

	while(fast && !circular)
	{
		if(!fast)
		{
			break;
		}
		fast = fast->next;

		if(!fast)
		{
			break;
		}
		fast = fast->next;

		slow = slow->next;

		if(fast == slow)
		{
			circular = true;
		}
	}

	return circular;
}

//=============================================================================
int getLoopSize(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();
	int loop = 0;

	if(!isCircular(linkedList))
	{
		loop = -1;
	}
	else
	{
		LinkedList::Node* slow = head;
		LinkedList::Node* fast = head;

		bool finished = false;
		while(!finished)
		{
			fast = fast->next->next;
			slow = slow->next;

			if(fast == slow)
			{
				do
				{
					fast = fast->next->next;
					slow = slow->next;
					loop++;
				}
				while(fast != slow);

				finished = true;
			}
		}
	}

	return loop;
}

//==============================================================================================================================================================
void makeFlat(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();

	if(isCircular(linkedList))
	{
		int loopSize = getLoopSize(linkedList);
		LinkedList::Node* ahead  = linkedList.getNth(loopSize);
		LinkedList::Node* curr   = head;
		LinkedList::Node* prev   = head;

		while(curr != ahead)
		{
			curr  = curr->next;
			prev  = ahead;
			ahead = ahead->next;
		}

		prev->next = nullptr;
	}
}

//==============================================================================================================================================================
void makeCircular(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();
	LinkedList::Node* tail = linkedList.getNth(linkedList.getLenght()- 1);

	tail->next = head;
}

//==============================================================================================================================================================
LinkedList concatenate(const LinkedList& l1, const LinkedList& l2)
{
	LinkedList result(l1.getHead());

	LinkedList::Node* n = result.getHead();
	while(n->next)
	{
		n = n->next;
	}

	n->next = l2.getHead();


	return result;
}

//==============================================================================================================================================================
int josephus(int n, int m)
{
	LinkedList people;
	for(int i = 0 ; i < n; i++)
	{
		people.addFront(i);
	}

	makeCircular(people);

	while(people.getLenght() != 1)
	{
		people.remove(m);
	}

	return people.getFront();
}

//==============================================================================================================================================================
void mergeAlternativeLists(const LinkedList& l1, LinkedList& l2)
{
	LinkedList::Node* n1     = l1.getHead();
	LinkedList::Node* n2     = l2.getHead();
	LinkedList::Node* prevN2 = n2;

	while(n1 && n2)
	{
		LinkedList::Node* nextN1 = n1->next;
		LinkedList::Node* nextN2 = n2->next;

		n2->next = n1;
		n1->next = nextN2;

		n1     = nextN1;
		prevN2 = n2; // in case we need to add at the end
		n2     = nextN2;
	}

	while(n1)
	{
		prevN2->next = n1;
		prevN2       = n1;
		n1           = n1->next;
	}
}

//==============================================================================================================================================================
LinkedList sum(const LinkedList& l1, const LinkedList& l2)
{
	// fill stack 1
	std::stack<int> stack1;
	LinkedList::Node* n1 = l1.getHead();
	while(n1)
	{
		stack1.push(n1->data);
		n1 = n1->next;
	}

	// fill stack 2
	std::stack<int> stack2;
	LinkedList::Node* n2 = l2.getHead();
	while(n2)
	{
		stack2.push(n2->data);
		n2 = n2->next;
	}


	LinkedList l3;

	int carry = 0;
	while(!stack1.empty() && !stack2.empty())
	{
		int a      = stack1.top();
		int b      = stack2.top();
		int sum    = a + b + carry;
		int result = sum % 10;
		carry      = (sum > 9 ? 1 : 0);

		l3.addFront(result);

		stack1.pop();
		stack2.pop();
	}

	while(!stack1.empty())
	{
		int a      = stack1.top();
		int sum    = a + carry;
		int result = sum % 10;
		carry      = (sum > 9 ? 1 : 0);

		l3.addFront(result);
		stack1.pop();
	}

	while(!stack2.empty())
	{
		int b = stack2.top();
		int sum = b + carry;
		int result = sum % 10;
		carry = (sum > 9 ? 1 : 0);

		l3.addFront(result);
		stack2.pop();
	}

	if(carry)
	{
		l3.addFront(carry);
	}

	return l3;
}

//==============================================================================================================================================================
void reverseWithSwap(LinkedList& linkedList)
{
	int length = linkedList.getLenght();
	for(int i = 0; i < length / 2; i++)
	{
		swapData(linkedList, i, length - i - 1);
	}

}

//==============================================================================================================================================================
void reverseInPlace(LinkedList& linkedList)
{
	LinkedList::Node* head   = linkedList.getHead();

	LinkedList::Node* second = head->next;
	LinkedList::Node* third  = second->next; // because we swap and we do not want to loose information

	second->next = head;  // do the actual swap. Now 2nd points to head
	head->next   = nullptr;
	head         = second;

	if(!third) // we are done and list it too small
	{
		return;
	}

	LinkedList::Node* curr = third;
	LinkedList::Node* prev = second;

	while(curr)
	{
		LinkedList::Node* next = curr->next;
		curr->next = prev; // link backwards

		prev = curr;
		curr = next;
	}

	head = prev; // will be the last one
}

//==============================================================================================================================================================
int getNthToLast(LinkedList& linkedList, int n)
{
	LinkedList::Node* head = linkedList.getHead();
	LinkedList::Node* n1 = head;
	LinkedList::Node* n2 = head;

	for(int i = 0; i < n; i++)
	{
		n1 = n1->next;
	}

	while(n1)
	{
		n1 = n1->next;
		n2 = n2->next;
	}

	return n2->data;
}

//==============================================================================================================================================================
void getNthToLastRecursive(LinkedList::Node* node, int n, int& outResult)
{
	if(node)
	{
		recursive getNthToLastRecursive(node->next, n, outResult);
	}

	static int i = 0;
	i++;

	if(i == n)
	{
		outResult = node->data;
	}
}

//=============================================================================
void viewReverseStack(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();

	std::stack<int> stack;
	for(LinkedList::Node* n = head; n != nullptr; n = n->next)
	{
		stack.push(n->data);
	}

	while(!stack.empty())
	{
		std::cout << " " << stack.top();
		stack.pop();
	}
}

//=============================================================================
void viewReverseRecursive(LinkedList::Node* n)
{
	if(n->next)
	{
		recursive viewReverseRecursive(n->next);
	}

	std::cout << " " << n->data;
}

//=============================================================================
void swapLinks(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2)
{
	int pos1 = linkedList.getPosition(n1);
	int pos2 = linkedList.getPosition(n2);

	int distance = std::abs(pos2 - pos1);
	if(distance == 0) // no need to swap same node
	{
		return;
	}

	if(pos2 < pos1) // be consistent. Order does not matter
	{
		std::swap(pos1, pos2);
	}

	LinkedList::Node* head = linkedList.getHead();

	if(!n1) // we have to swap head
	{
		if(distance == 1) // special case
		{
			LinkedList::Node* tmp      = n2->next;
			LinkedList::Node* saveN2   = n2->next->next;
			n2->next->next = head;
			head->next     = saveN2;
			head           = tmp;
		}
		else
		{
			LinkedList::Node* saveN2   = n2->next->next;
			LinkedList::Node* saveHead = head->next;
			LinkedList::Node* tmp      = head;

			head->next     = n2->next;
			head           = n2->next;

			n2->next->next = saveHead;
			n2->next       = tmp;
			tmp->next      = saveN2;
		}
	}
	else
	{
		if(distance == 1) // special case of distance 1
		{
			LinkedList::Node* sanveN2  = n2->next->next;

			n1->next       = n2->next;
			n2->next->next = n2;
			n2->next       = sanveN2;
		}
		else
		{
			LinkedList::Node* saveN1   = n1->next->next;
			LinkedList::Node* saveN2   = n2->next->next;

			LinkedList::Node* tmp      = n1->next;
			n1->next       = n2->next;

			n2->next->next = saveN1;
			n2->next       = tmp;
			tmp->next      = saveN2;
		}
	}
}

//=============================================================================
void swapData(LinkedList& linkedList, LinkedList::Node* n1, LinkedList::Node* n2)
{
	std::swap(n1->data, n2->data);
}

//=============================================================================
void swapData(LinkedList& linkedList, int pos1, int pos2)
{
	swapLinks(linkedList, linkedList.getNth(pos1), linkedList.getNth(pos2));
}

//=============================================================================
void remove(LinkedList& linkedlist, int startPosition, int removeCount)
{
	assert(startPosition >= 0 && startPosition < linkedlist.getLenght());
	assert(removeCount >=0 && removeCount < linkedlist.getLenght() - startPosition);

	LinkedList::Node* head = linkedlist.getHead();

	LinkedList::Node* curr = head;
	LinkedList::Node* prev = curr;
	int pos = 0;
	while(pos < startPosition)
	{
		pos++;
		prev = curr;
		curr = curr->next;
	}

	int removeIndex = 0;
	while(removeIndex < removeCount)
	{
		LinkedList::Node* toRemove = prev->next;
		prev->next = prev->next->next;

		delete toRemove;
		removeIndex++;
	}
}

//=============================================================================
LinkedList Union(const LinkedList& l1, const LinkedList& l2)
{
	LinkedList result;

	LinkedList::Node* n1 = l1.getHead();
	while(n1)
	{
		if(!result.find(n1->data))
		{
			result.addBack(n1->data);
		}
		n1 = n1->next;
	}

	LinkedList::Node* n2 = l2.getHead();
	while(n2)
	{
		if(!result.find(n2->data))
		{
			result.addBack(n2->data);
		}
		n2 = n2->next;
	}

	return result;
}

//=============================================================================
LinkedList Difference(const LinkedList& l1, const LinkedList& l2)
{
	LinkedList result;

	LinkedList::Node* n1 = l1.getHead();
	while(n1)
	{
		if(!l2.find(n1->data) && !result.find(n1->data))
		{
			result.addBack(n1->data);
		}
		n1 = n1->next;
	}
	
	return result;
}

//=============================================================================
LinkedList Intersection(const LinkedList& l1, const LinkedList& l2)
{
	LinkedList result;

	LinkedList::Node* n1 = l1.getHead();
	while(n1)
	{
		if(l2.find(n1->data) && !result.find(n1->data))
		{
			result.addBack(n1->data);
		}
		n1 = n1->next;
	}

	LinkedList::Node* n2 = l2.getHead();
	while(n2)
	{
		if(l1.find(n2->data) && !result.find(n2->data))
		{
			result.addBack(n2->data);
		}
		n2 = n2->next;
	}
	return result;
}

//=============================================================================
void seggregateEvenOdds(LinkedList& linkedList)
{
	LinkedList::Node* head = linkedList.getHead();
	LinkedList::Node* n    = head;
	LinkedList::Node* even = n;
	LinkedList::Node* odd  = n;

	while(n)
	{
		bool isEven = (n->data % 2 == 0 ? true : false);

		if(isEven)
		{

		}
		else
		{

		}

		n = n->next;
	}
}

} // namespace algorithm

