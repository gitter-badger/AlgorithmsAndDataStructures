#pragma once

#include <stack>


class Queue
{
	public:
		void enqueue(int val);
		int dequeue();
		bool isEmpty() const;


	private:
		std::stack<int> data;
		std::stack<int> buffer;
};