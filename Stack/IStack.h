#pragma once

class IStack
{
	public:
		virtual void reserve(int size) = 0;

		virtual void push(int item) = 0;

		virtual int pop() = 0;

		virtual int top() = 0;

		virtual bool isEmpty() = 0;
};