#pragma once

class Node
{
	public:
		Node(int x, int y) : x(x), y(y)
		{
			next = nullptr;
			down = nullptr;
		}

	public:
		int x;
		int y;
		Node* next;
		Node* down;
};
