#include "QuickFindAlgorithm.h"


//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
QuickFindAlgorithm::QuickFindAlgorithm(int nrNodes) : UnionFindTemplate(nrNodes)
{

}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void QuickFindAlgorithm::Initialize()
{
	if(!id.empty())
		id.clear();

	for (int i = 0; i < nrNodes; i++)
		id.push_back(i);
}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
bool QuickFindAlgorithm::Connected(int p, int q)
{
	return id[p] == id[q];
}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void QuickFindAlgorithm::Union(int p, int q)
{
	int totalElements = id.size();
	int idP = id[p];
	int idQ = id[q];

	for(int i = 0; i < totalElements; i++)
		if(id[i] == idP)
			id[i] = idQ;
}
