#pragma once

#include "UninonFindTemplate.h"

#include <vector>


class QuickUnionAlgorithm : public UnionFindTemplate
{
	public:
		virtual void Initialize(int n) override;
		virtual bool Connected(int p, int q) override;
		virtual void Union(int p, int q) override;
		virtual int Components() override;
};