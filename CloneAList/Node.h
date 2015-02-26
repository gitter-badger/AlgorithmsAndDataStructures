#pragma once

class Node
{
	public:
		Node(int data) : data(data)
		{
			next = nullptr;
			prev = nullptr;
		}

	public:
		int data;
		Node* next;
		Node* prev;
};

namespace factory
{
	Node* createRandPrevList();
}
