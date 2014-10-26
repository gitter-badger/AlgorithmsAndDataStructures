#pragma once

#include "IUnionFind.h"

#include <vector>

	
class UnionFindTemplate : public IUninonFind
{
	public:
		UnionFindTemplate(int nrNodes);

		virtual bool addPair(int p, int q);

		void view();

		int getNrConnectedComponents();

		float getAverageTreeHeight();

	protected:
		std::vector<int> id;
		int nrNodes;

	private:
		int nrConnectedComponents;
		int nrUnionOperations;
};