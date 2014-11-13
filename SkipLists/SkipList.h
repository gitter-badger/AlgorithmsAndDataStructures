#pragma once

#include <vector>
#include <random>


class SkipList
{
	public:
		SkipList();

		void insert(int element);

		bool find(int element);
		void view();


	private:
		void insert(int element, int listLevel);

		bool flipCoin();


		class Node
		{
			public:
				Node(int data = 0) : data(data)
				{
					const int maxSize = 13;

					for(int i = 0; i < maxSize; i++)
						next.push_back(nullptr);
				}

				std::vector<Node*> next;
				int data;
		};

		std::mt19937 engine;
		std::uniform_int_distribution<int> distribution;
		Node* head;
		int maxLevel;
};