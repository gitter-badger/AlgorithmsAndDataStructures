#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

//================================================================================================================================================================
std::vector<int> getPrimes(int n)
{
	std::vector<int> numbers(n, 1);

	for(int i = 2; i < n; i++)
		if(numbers[i] == 1)
			for(int j = i; j*i < n; j++)
				numbers[j * i] = 0;

	std::vector<int> primes;
	for(int i = 2; i < n; i++)
		if(numbers[i] == 1)
			primes.push_back(i);

	return primes;
}

//================================================================================================================================================================
int main()
{
	auto primes = getPrimes(10000);
	for(auto p : primes)
		std::cout << std::endl << p;


	std::cout << std::endl;
	return 0;
}