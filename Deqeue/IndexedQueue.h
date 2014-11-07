#pragma once

#include "Queue.h"

#include <array>


template<typename T, int max_size> class IndexedQueue
{
public:
	//================================================================================================================================================================
	IndexedQueue()
	{
		elements.fill(0);
	}

	//================================================================================================================================================================
	void enqueue(const T& data)
	{
		if(!elements[data])
		{
			queue.enqueue(data);
			elements[data] = 1;
		}
	}

	//================================================================================================================================================================
	T dequeue()
	{
		return queue.dequeue();
	}

	//================================================================================================================================================================
	T front()
	{
		return queue.front();
	}

	//================================================================================================================================================================
	bool isEmpty()
	{
		return queue.isEmpty();
	}

private:
	std::array<int, max_size> elements;
	Queue<T> queue;
};