#include "IUnionFind.h"
#include "QuickFindAlgorithm.h"
#include "QuickUnionAlgorithm.h"
#include "WeightedQuickUnion.h"
#include "WeightedQuickUnionPathCompression.h"
#include "RandomTestData.h"

#include <iostream>
#include <memory>
#include <chrono>
#include <tuple>


template<typename A>
void interractiveAlgorithmTest()
{
	int nrNodes = -1;
	int p = -1;
	int q = -1;

	std::cout << "NrNodes: ";
	std::cin >> nrNodes;

	std::unique_ptr<IUninonFind> unionFindAlgorithm = std::make_unique<A>(nrNodes);

	unionFindAlgorithm->Initialize();

	do
	{
		std::cout << "\n----------------------------";
		std::cout << "\ninput (p-q) pair: ";
		std::cin >> p >> q;

		if(p != -1 && p != -1)
		{
			if(unionFindAlgorithm->addPair(p, q))
			{
				std::cout << "\t- Added!";
				unionFindAlgorithm->view();
			}
			else
			{
				std::cout << "\t- Already connected!";
			}
		}
	}
	while(p != -1 && q != -1);
}

template<typename A>
std::tuple<float, float> analyzePerformance(std::vector<std::pair<int,int>>& testData, int nrNodes)
{
	std::unique_ptr<IUninonFind> unionFindAlgorithm = std::make_unique<A>(nrNodes);

	auto start = std::chrono::system_clock::now();

	unionFindAlgorithm->Initialize();
	for(auto& pqPair : testData)
		unionFindAlgorithm->addPair(pqPair.first, pqPair.second);

	auto end     = std::chrono::system_clock::now();
	auto elapsed = end - start;


	float duration          = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
	float averageTreeHeight = unionFindAlgorithm->getAverageTreeHeight();

	return std::make_tuple(duration, averageTreeHeight);
}

void performanceAnalyzer()
{
	int nrNodes = 100000;
	__int32 nrPairs = 10000;
	std::cout << "Generating data...";
	RandomTestData randomTestData(nrNodes - 1, nrPairs);
	auto data = randomTestData.generateTestData();
	std::cout << "DONE!";


	float duration, averageTreeHeight;

	std::tie(duration, averageTreeHeight) = analyzePerformance<WeightedQuickUnion>(data, nrNodes);
	std::cout << "\nWeightedQuickUnion: "; std::cout << duration << "ms treeHeight: " << averageTreeHeight;

	std::tie(duration, averageTreeHeight) = analyzePerformance<WeightedQuickUnionPathCompression>(data, nrNodes);
	std::cout << "\nWeightedQuickUnionPathCompression: "; std::cout << duration << "ms treeHeight: " << averageTreeHeight;
	//std::cout << "\nQuickUnionAlgorithm: "; std::cout << analyzePerformance<QuickUnionAlgorithm>(data, nrNodes);
	//std::cout << "\nQuickFindAlgorithm: "; std::cout << analyzePerformance<QuickFindAlgorithm>(data, nrNodes);

	std::cout << std::endl << std::endl;
}

int main()
{
	interractiveAlgorithmTest<WeightedQuickUnionPathCompression>();
	//performanceAnalyzer();

	

	return 0;
}