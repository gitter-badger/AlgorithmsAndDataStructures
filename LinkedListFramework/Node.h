#pragma once

namespace linkedlist
{
	class Node
	{
		public:
			inline Node(int data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev)	{ }

		public:
			int data;
			Node* next;
			Node* prev; // optional. Used only for double linked lists
	};


}