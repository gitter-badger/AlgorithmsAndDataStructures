#pragma once

#include "UninonFindTemplate.h"


class WeightedQuickUnionPathCompression : public UnionFindTemplate
{
	public:
		WeightedQuickUnionPathCompression(int nrNodes);

		virtual void Initialize();
		virtual bool Connected(int p, int q);
		virtual void Union(int p, int q);
};