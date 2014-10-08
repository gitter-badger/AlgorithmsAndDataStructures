#include "RandomTestData.h"

#include <random>
#include <vector>
#include <algorithm>


//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
RandomTestData::RandomTestData(int nrElements, int nrPairs) : nrElements(nrElements),
											      nrPairs(nrPairs),
												  distribution(0, nrElements)
											      
{
	std::random_device randomDevice;
	engine.seed(randomDevice());
}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
std::vector<std::pair<int,int>> RandomTestData::generateTestData()
{
	std::vector<std::pair<int,int>> randomGeneratedDta(nrPairs);

	std::transform(randomGeneratedDta.begin(), randomGeneratedDta.end(), randomGeneratedDta.begin(), [this](std::pair<int,int> element)
	{
		return std::make_pair<int,int>(distribution(engine), distribution(engine));
	});

	return randomGeneratedDta;
}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
int RandomTestData::getNrPairs() const
{
	return nrPairs;
}
