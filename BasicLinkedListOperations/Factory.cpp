#include "Factory.h"

namespace factory
{

//==============================================================================================================================================================
LinkedList createFromNumber(__int64 n)
{
	LinkedList result;

	while(n)
	{
		int d = n % 10;
		result.addFront(d);
		n /= 10;
	}

	return result;
}

//=============================================================================
LinkedList createFromVector(const std::vector<int>& elements)
{
	LinkedList result;

	for(auto e : elements)
	{
		result.addBack(e);	
	}

	return result;
}

} // namespace factory
