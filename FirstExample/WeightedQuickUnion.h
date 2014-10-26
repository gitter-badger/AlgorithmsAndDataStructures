#pragma once

#include "UninonFindTemplate.h"

#include <vector>


class WeightedQuickUnion : public UnionFindTemplate
{
	public:
		WeightedQuickUnion(int nrNodes);

		virtual void Initialize() override;
		virtual bool Connected(int p, int q) override;
		virtual void Union(int p, int q) override;
		virtual float getAverageTreeHeight() override;

	private:
		int root(int i);

		std::vector<int> sz;
};
