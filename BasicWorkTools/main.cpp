#include <iostream>
#include <random>
#include <limits.h>
#include <string>

//================================================================================================================================================================
int generateRandom()
{
	static std::random_device randomDevice;
	static std::mt19937 engine;
	static std::uniform_int_distribution<int> distribution(10, 20);
	//engine.seed(randomDevice());

	return distribution(engine);
}

//================================================================================================================================================================
template<typename T>
void viewLimits()
{
	std::cout << std::endl << "-------";
	std::cout << std::endl << "name: " << typeid(T).name();
	std::cout << std::endl << "size: " << sizeof(T);
	std::cout << std::endl << "min:  " << std::numeric_limits<T>::min();
	std::cout << std::endl << "max:  " << std::numeric_limits<T>::max();
}

//================================================================================================================================================================
namespace boo
{
class MySuperClass{};
}

//================================================================================================================================================================
int main()
{
	//for(int i = 0 ; i <100; i++)
	//	std::cout << std::endl << " random number: " << generateRandom();

	viewLimits<char>();
	viewLimits<int>();
	viewLimits<size_t>();
	viewLimits<__int64>();
	viewLimits<float>();
	viewLimits<double>();

	std::cout << std::endl << "user defined name: " << typeid(boo::MySuperClass).name();

	std::cout << std::endl;
	return 0;
}