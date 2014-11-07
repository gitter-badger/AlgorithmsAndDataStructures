#include "WeightedQuickUnion.h"

#include <numeric>


//================================================================================================================================================================
WeightedQuickUnion::WeightedQuickUnion(int nrNodes) : UnionFindTemplate(nrNodes)
{

}

//================================================================================================================================================================
void WeightedQuickUnion::Initialize()
{
	if(!id.empty())
		id.clear();

	for(int i=0; i<nrNodes; i++)
	{
		id.push_back(i);
		sz.push_back(1); // each node has a height of 1 initially
	}
}

//================================================================================================================================================================
bool WeightedQuickUnion::Connected(int p, int q)
{
	return root(p) == root(q);
}

//================================================================================================================================================================
void WeightedQuickUnion::Union(int p, int q)
{
	int i = root(p);
	int j = root(q);

	// we avoid one line trees and by balancing the tree
	if(sz[i] < sz[j])
	{
		id[i]   = j; // connect the small tree to the big tree
		sz[j] += sz[i];
	}
	else
	{
		id[j]   = i; // connect the big tree to the small tree
		sz[i] += sz[j];
	}
}

//================================================================================================================================================================
int WeightedQuickUnion::root(int i)
{
	while(i != id[i])
		i = id[i];

	return i;
}

//================================================================================================================================================================
float WeightedQuickUnion::getAverageTreeHeight()
{
	return static_cast<float>(std::accumulate(sz.begin(), sz.end(), 0)) / static_cast<float>(sz.size());
}
