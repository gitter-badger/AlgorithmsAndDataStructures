#include "LinearSearch.h"
#include "BinarySearch.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>
#include <chrono>
#include <string>


//================================================================================================================================================================
std::vector<size_t> generateTestData(size_t size)
{
	std::vector<size_t> elements(size);
	
	std::cout << std::endl << "Generating test data...";
	for(size_t i=0; i<size; i++)
		elements[i] = i;
	std::cout << std::endl << "DONE!\n";

	return elements;
}

//================================================================================================================================================================
void testSearchAlgorithm(const std::string& algorithmName,
					     const std::unique_ptr<basicsearching::ISearch> &searchAlgorithm,
						 const std::vector<size_t>& elements, size_t key)
{
	std::cout << std::endl << algorithmName;

	auto start = std::chrono::system_clock::now();
	bool found = searchAlgorithm->search(elements, key);
	std::cout << std::endl << "Found: " << found;

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
	std::cout << std::endl << "Duration: " << duration.count() << " ms";
}

//================================================================================================================================================================
int main()
{
	auto elements = generateTestData(std::pow(10, 4));
	size_t key    = -1; // an element which is never found

	std::unique_ptr<basicsearching::ISearch> linearSearch = std::make_unique<basicsearching::LinearSearch>();
	std::unique_ptr<basicsearching::ISearch> binarySearch = std::make_unique<basicsearching::BinarySearch>();

	testSearchAlgorithm("LinearSearch", linearSearch, elements, key);
	std::cout << std::endl << "-----------";
	testSearchAlgorithm("BinarySearch", binarySearch, elements, key);


	std::cout << std::endl;
	return 0;
}