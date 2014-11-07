#include "BinarySearch.h"
#include <iostream>


//================================================================================================================================================================
bool basicsearching::BinarySearch::search(const std::vector<size_t>& elements, size_t key)
{
	size_t left  = 0;
	size_t right = elements.size()-1;

	while(right >= left)
	{
		size_t middle = (left + right) / 2;

		if(elements[middle] == key)
			return true;

		if(key < elements[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}


	return false;
}
