#pragma once

#include <random>
#include <utility>


class RandomTestData
{
	public:
		RandomTestData(int nrElements, int nrPairs);

		std::vector<std::pair<int,int>> generateTestData();

	private:
		int nrElements;
		int nrPairs;

		std::mt19937 engine;
		std::uniform_int_distribution<int> distribution;
};