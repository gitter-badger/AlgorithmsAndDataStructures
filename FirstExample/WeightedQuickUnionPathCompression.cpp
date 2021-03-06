#include "WeightedQuickUnionPathCompression.h"

#include <numeric>


//================================================================================================================================================================
WeightedQuickUnionPathCompression::WeightedQuickUnionPathCompression(int nrNodes) : UnionFindTemplate(nrNodes)
{

}

//================================================================================================================================================================
void WeightedQuickUnionPathCompression::Initialize()
{
	if(!id.empty())
		id.clear();

	for(int i = 0; i < nrNodes; i++)
	{
		id.push_back(i);
		sz.push_back(1); // each node has a height of 1 initially




















	}
}

//================================================================================================================================================================
bool WeightedQuickUnionPathCompression::Connected(int p, int q)
{
	return root(p) == root(q);
}

//================================================================================================================================================================
void WeightedQuickUnionPathCompression::Union(int p, int q)
{
	int i = root(p);
	int j = root(q);

	// we avoid one line trees and by balancing the tree
	if(sz[i] < sz[j])
	{
		id[i] = j; // connect the small tree to the big tree
		sz[j] += sz[i];
	}
	else
	{
		id[j] = i; // connect the big tree to the small tree
		sz[i] += sz[j];
	}
}

//================================================================================================================================================================
int WeightedQuickUnionPathCompression::root(int i)
{
	while(i != id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
	}

	return i;
}

//================================================================================================================================================================
float WeightedQuickUnionPathCompression::getAverageTreeHeight()
{
	return static_cast<float>(std::accumulate(sz.begin(), sz.end(), 0)) / static_cast<float>(sz.size());
}
