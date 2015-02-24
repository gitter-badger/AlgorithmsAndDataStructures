#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
void algorithm::flatten(Node* head)
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
