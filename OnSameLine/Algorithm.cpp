#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
void algorithm::ViewPointList(Node* node)
{
	Node* n = node;
	while(n)
	{
		std::cout << "(" << n->x << ", " << n->y << ") -> ";
		n = n->next;
	}
}

//=============================================================================
void algorithm::RemovePointsFromLines(Node* node)
{
	Node* n1 = node;
	Node* n2 = n1->next;
	Node* n3 = n2->next;

	while(n3)
	{
		if(areOnSameLine(n1, n2, n3))
		{
			delete n2;
			n1->next = n3;
		}
		else
		{
			n1 = n1->next;
		}

		n2 = n1->next;
		n3 = n2->next;
	}
}

//=============================================================================
bool algorithm::areOnSameLine(const Node* n1, const Node* n2, const Node* n3)
{
	return (n1->x == n2->x && n2->x == n3->x) || (n1->y == n2->y && n2->y == n3->y);
}
