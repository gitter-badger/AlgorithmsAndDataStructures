#include "Factory.h"
#include "Node.h"
#include "Algorithm.h"

#include <iostream>
#include <vector>
#include <tuple>


int main()
{
	std::vector<std::tuple<int,int>> points;
	points.emplace_back(0, 10);
	points.emplace_back(1, 10);
	points.emplace_back(3, 10);
	points.emplace_back(4, 10);
	points.emplace_back(5, 11);
	points.emplace_back(6, 11);
	points.emplace_back(7, 12);
	points.emplace_back(8, 12);
	points.emplace_back(9, 12);
	points.emplace_back(13, 13);

	std::reverse(points.begin(), points.end());

	Node* list = factory::CreateListFromPoints(points);

	algorithm::RemovePointsFromLines(list);

	algorithm::ViewPointList(list);


	std::cout << std::endl << "\n";
	return 0;
}