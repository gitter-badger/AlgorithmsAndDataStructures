#include "LinearSearch.h"


//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
bool basicsearching::LinearSearch::search(const std::vector<size_t>& elements, size_t key)
{
	bool found = false;

	for(size_t i =  0; i < elements.size(); i++)
		if(elements[i] == key)
			found = true;

	return found;
}
