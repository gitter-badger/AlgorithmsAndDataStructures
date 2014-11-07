#include "UninonFindTemplate.h"

#include <iostream>


//================================================================================================================================================================
UnionFindTemplate::UnionFindTemplate(int nrNodes) : nrNodes(nrNodes)
{
	nrConnectedComponents = nrNodes;
	nrUnionOperations     = 0;
}

//================================================================================================================================================================
bool UnionFindTemplate::addPair(int p, int q)
{
	if(!Connected(p, q))
	{
		Union(p, q);
		nrUnionOperations++;

		return true;
	}
	else
		return false;
}

//================================================================================================================================================================
int UnionFindTemplate::getNrConnectedComponents()
{
	return (nrConnectedComponents - nrUnionOperations);
}

//================================================================================================================================================================
void UnionFindTemplate::view()
{
	std::cout << " id[]:";
	for(auto& element : id)
		std::cout << " " << element;
}

//================================================================================================================================================================
float UnionFindTemplate::getAverageTreeHeight()
{
	return -1;
}
