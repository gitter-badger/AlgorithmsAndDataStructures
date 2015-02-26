#pragma once

#include <vector>
#include <tuple>


class Node;


namespace factory
{
	Node* CreateListFromPoints(const std::vector<std::tuple<int,int>>& points);
}