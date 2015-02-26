#include "Factory.h"
#include "Node.h"
#include <iostream>


//=============================================================================
Node* factory::CreateListFromPoints(const std::vector<std::tuple<int,int>>& points)
{
	Node* head = nullptr;
	int x, y;

	for(const auto& point : points)
	{
		std::tie(x, y) = point;
		Node* newNode = new Node(x, y);

		if(!head)
		{
			head = newNode;
			head->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	return head;
}
