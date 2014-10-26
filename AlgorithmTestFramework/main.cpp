#include "Algorithm.h"
#include "AlgorithmFramework.h"

#include <iostream>


class BinarySearch : public Algorithm
{
	public:
		BinarySearch() : Algorithm("BinarySearch") {}
		virtual void run(){std::this_thread::sleep_for(std::chrono::seconds(1));}
		virtual void init(int n){}
};

class LinearSearch : public Algorithm
{
	public:
		LinearSearch() : Algorithm("LinearSearch") {}
		virtual void run(){}
		virtual void init(int n){}
};


int main()
{
	AlgorithmFramework algorithmFramework;

	std::vector<int> samples{100, 200, 400, 800};
	algorithmFramework.addAlgorithm(new BinarySearch(), samples);
	algorithmFramework.addAlgorithm(new LinearSearch(), {10, 20, 30, 40, 50, 60, 70});

	algorithmFramework.test();


	std::cout << std::endl << std::endl;
	return 0;
}