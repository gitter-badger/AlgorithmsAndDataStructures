#pragma once

namespace linkedlist
{
	namespace singly
	{
		template<typename T>
		class Node
		{
			public:
				inline Node(T data, Node* next = nullptr) : data(data), next(next) { }

			public:
				T data;
				Node* next;
		};
	} // namespace singly

	namespace doubly
	{
		template<typename T>
		class Node
		{
			public:
				inline Node(T data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) { }

			public:
				T data;
				Node* next;
				Node* prev;
		};
	} // namespace doubly
} // namespace single