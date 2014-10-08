#pragma once

#include <vector>
#include <utility>


class TestData
{
	public:
		void addPair(int p, int q);
		std::vector<std::pair<int, int>> getData();

	private:
		std::vector<std::pair<int, int>> testData;
};