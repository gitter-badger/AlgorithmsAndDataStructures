#pragma once

#include "IUnionFind.h"

#include <vector>

	
class UnionFindTemplate : public IUninonFind
{
	public:
		virtual bool addPair(int p, int q);

	protected:
		std::vector<int> elements;
};