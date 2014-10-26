#pragma once

#include "Algorithm.h"

#include <chrono>
#include <thread>


class BinarySearch : public algorithm::Algorithm
{
	public:
	BinarySearch() : Algorithm("BinarySearch")
	{
	}
	virtual void run()
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	virtual void init(int n)
	{
	}
};

class LinearSearch : public algorithm::Algorithm
{
	public:
	LinearSearch() : Algorithm("LinearSearch")
	{
	}
	virtual void run()
	{
	}
	virtual void init(int n)
	{
	}
};