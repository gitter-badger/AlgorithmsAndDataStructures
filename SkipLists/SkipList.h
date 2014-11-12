#pragma once

class SkipList
{
	public:
		SkipList();

		void insert(int element);
		bool find(int element);
		void view();

	private:
		class Node
		{
			public:
				Node(int data = 0) : data(data)
				{

				}

				Node* next;
				int data;
		};

		Node* head;
};