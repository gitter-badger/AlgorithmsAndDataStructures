#pragma once

#include <vector>
#include <random>


class SkipList
{
	class Node;

	public:
		SkipList();

		void insert(int element);

		Node* find(int element);
		void view();


	private:
		bool flipCoin();

		class Node
		{
		public:
			Node(int data = 0) : data(data)
			{
				prev = nullptr;
				down = nullptr;
				up   = nullptr;
				down = nullptr;
			}

			Node* prev;
			Node* next;
			Node* up;
			Node* down;
			int data;
		};

		std::mt19937 engine;
		std::uniform_int_distribution<int> distribution;

		int height;
		Node* header;
		Node* trail;
};