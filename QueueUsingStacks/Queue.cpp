#include "Queue.h"

//=============================================================================
void Queue::enqueue(int val)
{
	data.push(val);
}

//=============================================================================
int Queue::dequeue()
{
	if(isEmpty())
	{
		throw std::exception("empty_queue");
	}

	while(!data.empty())
	{
		buffer.push(data.top());
		data.pop();
	}

	int front = buffer.top();
	buffer.pop();

	while(!buffer.empty())
	{
		data.push(buffer.top());
		buffer.pop();
	}

	return front;
}

//=============================================================================
bool Queue::isEmpty() const
{
	return data.empty();
}
