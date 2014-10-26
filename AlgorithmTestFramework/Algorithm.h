#pragma once

#include <string>


class Algorithm
{
	public:
		Algorithm(const std::string& name);

		std::string getName() const;

		// Will run the algorithm
		virtual void run() = 0;

		// It is called before running the algorithm
		// The client must correctly initialize the data for the algorithm
		virtual void init(int n) = 0;

	private:
		std::string name; // each algorithm has a unique name
};