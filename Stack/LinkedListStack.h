#pragma once

#include "IStack.h"


class LinkedListStack : public IStack
{
	public:
		LinkedListStack();
		virtual void push(int item);
		virtual int pop();
		virtual int top();
		virtual bool isEmpty();

	private:
		virtual void reserve(int size) override {} 

		class Node
		{
			public:
				Node(int data) : data(data), next(nullptr) {}
				int data;
				Node* next;
		};

		Node* head;
};