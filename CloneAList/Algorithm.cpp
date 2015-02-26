#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
Node* algorithm::Clone(Node* head1)
{
	Node* head2 = nullptr;
	Node* n1 = head1;
	Node* prevN2;

	while(n1->next)
	{
		Node* n2 = new Node(n1->data);
		Node* saveN1 = n1->next;

		n1->next = n2;
		n2->prev = saveN1;
		n2->next = new Node(saveN1->data);

		n1 = saveN1;

		if(!head2)
		{
			head2 = n2;
		}

	}


	return head2;
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
