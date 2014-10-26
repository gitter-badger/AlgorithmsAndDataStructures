#pragma once

#include <vector>

namespace basicsearching
{
	class ISearch
	{
		public:
			virtual bool search(const std::vector<size_t>& elements, size_t key) = 0;
	};
}