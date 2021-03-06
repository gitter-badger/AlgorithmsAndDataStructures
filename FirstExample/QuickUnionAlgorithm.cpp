#include "QuickUnionAlgorithm.h"


//================================================================================================================================================================
QuickUnionAlgorithm::QuickUnionAlgorithm(int nrNodes) : UnionFindTemplate(nrNodes)
{
}

//================================================================================================================================================================
void QuickUnionAlgorithm::Initialize()
{
	if(!id.empty())
		id.clear();

	for(int i=0; i<nrNodes; i++)
		id.push_back(i);
}

//================================================================================================================================================================
bool QuickUnionAlgorithm::Connected(int p, int q)
{
	return root(p) == root(q);
}

//================================================================================================================================================================
void QuickUnionAlgorithm::Union(int p, int q)
{
	int i = root(p);
	int j = root(q);
	id[i] = j;
}

//================================================================================================================================================================
int QuickUnionAlgorithm::root(int i)
{
	while(i != id[i])
		i = id[i];

	return i;
}



