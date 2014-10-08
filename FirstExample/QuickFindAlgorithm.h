#pragma once

#include "UninonFindTemplate.h"

#include <vector>


class QuickFindAlgorithm : public UnionFindTemplate
{
	public:
		QuickFindAlgorithm(int nrNodes);

		virtual void Initialize() override;
		virtual bool Connected(int p, int q) override;
		virtual void Union(int p, int q) override;
};