#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


namespace utils
{

//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<int> generateRandomVector(unsigned long size, int lowerBound, int upperBound)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(lowerBound, upperBound);

    std::vector<int> v(size);
    std::generate(v.begin(), v.end(), [&dist, &mt]()
    {
        return dist(mt);
    });

    return v;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
template<typename F>
void testFunction(const F& testFunction, int nrIterations, int sampleSize)
{
    std::cout << std::endl << "Computing ...";

    auto start = std::chrono::system_clock::now();

    for(int i = 0; i < nrIterations; i++)
    {
        std::vector<int> v = generateRandomVector(sampleSize, -20, 20);
        testFunction(v, 0, v.size() - 1);
    }

    auto duration = std::chrono::system_clock::now() - start;

    std::cout << " done = " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms";
}

} // namespace utils