#pragma once

#include "UninonFindTemplate.h"

#include <vector>


class QuickUnionAlgorithm : public UnionFindTemplate
{
	public:
		QuickUnionAlgorithm(int nrNodes);

		virtual void Initialize() override;
		virtual bool Connected(int p, int q) override;
		virtual void Union(int p, int q) override;

	private:
		int root(int i);

};