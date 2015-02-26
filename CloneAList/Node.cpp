#include "Node.h"

//=============================================================================
Node* factory::createRandPrevList()
{
	Node* n1 = new Node(0);
	Node* n2 = new Node(1);
	Node* n3 = new Node(2);
	Node* n4 = new Node(3);
	Node* n5 = new Node(4);
	Node* n6 = new Node(5);
	Node* n7 = new Node(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = nullptr;

	n1->prev = n7;
	n7->prev = n2;
	n2->prev = n6;
	n6->prev = n3;
	n3->prev = n5;
	n5->prev = n4;
	n4->prev = nullptr;

	Node* head = n1;
	return head;
}
