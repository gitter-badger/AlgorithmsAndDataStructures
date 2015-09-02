#include "Utils.h"
#include "MSS.h"
#include "Data.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
#include <functional>


//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    unsigned long sampleSize = 100;
    int nrIterations         = 100;

    utils::testFunction(method2::findMaxSum, sampleSize, nrIterations);
    utils::testFunction(method3::findMaxSum, sampleSize, nrIterations);
    utils::testFunction(method1::findMaxSum, sampleSize, nrIterations);
    utils::testFunction(method4::findMaxSum, sampleSize, nrIterations);

    int left, right, result1;

    auto v = utils::generateRandomVector(sampleSize, -20, 20);
    std::tie(left, right, result1) = method1::findMaxSum(v, 0, v.size() - 1);
    Data result2                   = method2::findMaxSum(v, 0, v.size() - 1);
    int result3                    = method3::findMaxSum(v, 0, v.size() - 1);
    int result4                    = method4::findMaxSum(v, 0, v.size() - 1);


    std::cout << "\n";
    std::cout << "\nO(n^2)     sum = " << result1;
    std::cout << "\nO(nlng)_m1 sum = " << result2.sum;
    std::cout << "\nO(nlng)_m2 sum = " << result3;
    std::cout << "\nO(n^3)     sum = " << result4;

    std::cout << std::endl << "\n\n";
    return 0;
}