#include "TestData.h"


//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void TestData::addPair(int p, int q)
{
	testData.emplace_back(p, q);
}

//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
std::vector<std::pair<int, int>> TestData::getData()
{
	return testData;

}
