#pragma once

#include "ISearch.h"


namespace basicsearching
{
	class BinarySearch : public ISearch
	{
		public:
			virtual bool search(const std::vector<size_t>& elements, size_t key);
	};
}