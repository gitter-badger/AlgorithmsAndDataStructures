#pragma once

#include "Data.h"

#include <tuple>
#include <vector>


namespace method1
{
std::tuple<int, int, int> findMaxSum(const std::vector<int>& v, int low, int high);
}

namespace method2
{
Data findMaxCrossingSubarray(const std::vector<int>& v, int low, int mid, int high);
Data findMaxSum(const std::vector<int>& v, int low, int high);
}

namespace method3
{
int findMaxSum(const std::vector<int>& v, int low, int high);
}

namespace method4
{
    int findMaxSum(const std::vector<int>& v, int low, int high);
}