#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
void algorithm::flattenSorted(Node* head)
{
	Node* n = head;
	while(n)
	{
		Node* d = n->down;

		while(d)
		{
			Node* saveDown = d->down;
			Node* tmp      = head;
			Node* prev     = tmp;

			while(tmp && d->data > tmp->data)
			{
				prev = tmp;
				tmp  = tmp->next;
			}

			d->next    = prev->next;
			prev->next = d;

			d->down    = nullptr;

			d = saveDown;
		}

		n = n->next;
	}
}

//=============================================================================
void algorithm::view(Node* head)
{
	Node* n = head;
	while(n)
	{
		std::cout << " " << n->data;
		n = n->next;
	}
}

//=============================================================================
void algorithm::flatten(Node* head)
{
	Node* n = head;

	while(n)
	{
		Node* next  = n->next;
		Node* d     = n->down;
		Node* prevD = d;

		while(d)
		{
			n->next = d;
			n = d;
			prevD = d;
			d = d->down;
		}

		prevD->next = next;
		n = next;
	}
}
