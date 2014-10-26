#pragma once

class IList
{
	public:
		// views the list elements
		virtual void view() = 0;

		// adds a new node to the front of the list
		virtual void addFront(int n) = 0;

		// removes the first node with the value n
		virtual void remove(int n) = 0;

		// return true if it finds the node with the value of n
		virtual bool find(int n) = 0;

		virtual void reverse() = 0;

		virtual void sort() = 0;
};