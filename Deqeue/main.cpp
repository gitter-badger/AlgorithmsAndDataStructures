#include "Stack.h"
#include "Queue.h"
#include "IndexedStack.h"
#include "IndexedQueue.h"

#include <iostream>

//================================================================================================================================================================
void testStack(int nrElements)
{
	Stack<int> stack;

	for(int i = 0; i < nrElements; i++)
		stack.push(i);

	std::cout << "stack: ";
	while(!stack.isEmpty())
		std::cout << stack.pop() << " ";
}

//================================================================================================================================================================
void testQueue(int nrElements)
{
	Queue<int> queue;

	for(int i = 0; i < nrElements; i++)
		queue.enqueue(i);

	std::cout << "queue: ";
	while(!queue.isEmpty())
		std::cout << queue.dequeue() << " ";
}

//================================================================================================================================================================
void testIndexedStack()
{
	IndexedStack<int, 3> stack;

	stack.push(0);
	stack.push(0);
	stack.push(0);
	stack.push(1);
	stack.push(1);
	stack.push(2);

	std::cout << "indexed_stack: ";
	while(!stack.isEmpty())
		std::cout << stack.pop() << " ";
}

//================================================================================================================================================================
void testIndexedQueue()
{
	IndexedQueue<int, 3> queue;

	queue.enqueue(0);
	queue.enqueue(0);
	queue.enqueue(0);
	queue.enqueue(1);
	queue.enqueue(1);
	queue.enqueue(2);

	std::cout << "indexed_queue: ";
	while(!queue.isEmpty())
		std::cout << queue.dequeue() << " ";
}


int main()
{
	testStack(10);
	std::cout << "\n";
	testQueue(10);
	std::cout << "\n";
	testIndexedStack();
	std::cout << "\n";
	testIndexedQueue();


	std::cout << "\n\n";
	return 0;
}