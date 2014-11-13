#pragma once

#include "Deqeue.h"


template<typename T> class Queue
{
	public:
		//================================================================================================================================================================
		void enqueue(const T& data)
		{
			container.addBack(data);
		}

		//================================================================================================================================================================
		T dequeue()
		{
			T item = container.getFront();
			container.removeFront();

			return item;
		}

		//================================================================================================================================================================
		T front()
		{
			return container.getFront();
		}

		//================================================================================================================================================================
		bool isEmpty()
		{
			return container.isEmpty();
		}
			
	private:
		Dequeue<T> container;
};