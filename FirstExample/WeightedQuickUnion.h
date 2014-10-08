#pragma once

#include "UninonFindTemplate.h"


class WeightedQuickUnion : public UnionFindTemplate
{
	public:
		WeightedQuickUnion(int nrNodes);

		virtual void Initialize();
		virtual bool Connected(int p, int q);
		virtual void Union(int p, int q);

	private:
		int root(int i, int& treeSize);
};
