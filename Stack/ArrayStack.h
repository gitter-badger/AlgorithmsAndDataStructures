#include "IStack.h"


class ArrayStack : public IStack
{
	public:
		ArrayStack(int size);

		~ArrayStack();

		virtual void push(int item);

		virtual int pop();

		virtual void reserve(int size);

		virtual int top();

		virtual bool isEmpty();

	private:
		int index;
		int* elements;
		int maxSize;
};