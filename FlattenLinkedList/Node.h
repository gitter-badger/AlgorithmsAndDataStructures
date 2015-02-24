#pragma once


class Node
{
	public:
		Node(int data) : data(data)
		{
			next = nullptr;
			down = nullptr;
		}

	public:
		int data;
		Node* next;
		Node* down;
};

namespace factory
{
	Node* createMultiLevelLinkedList();
}