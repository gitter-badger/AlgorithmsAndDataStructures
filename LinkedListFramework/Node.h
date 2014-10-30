#pragma once

namespace linkedlist
{
	template<typename T>
	class Node
	{
		public:
			inline Node(T data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) { }

		public:
			T data;
			Node* next;
			Node* prev; // optional. Used only for double linked lists
	};
}