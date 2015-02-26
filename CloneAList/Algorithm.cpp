#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
Node* algorithm::Clone(Node* head)
{
	return nullptr;
}

//=============================================================================
void algorithm::ViewPrev(Node* head)
{
	Node* n = head;

	while(n)
	{
		std::cout << n->data << " ";
		n = n->prev;
	}
}

//=============================================================================
void algorithm::ViewNext(Node* head)
{
	Node* n = head;

	while(n)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
}
