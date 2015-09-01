#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <random>
#include <chrono>


//----------------------------------------------------------------------------------------------------------------------------------------------
struct Data
{
    int low;
    int high;
    int sum;

    Data(int low, int high, int sum) : low(low), high(high), sum(sum) {}
};

//----------------------------------------------------------------------------------------------------------------------------------------------
std::tuple<int, int, int> findMaxSum(const std::vector<int>& v)
{
    int maxSum = std::numeric_limits<int>::min();
    int left   = 0;
    int right  = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];

            if (sum > maxSum)
            {
                maxSum = sum;
                right  = j;
                left   = i;
            }
        }
    }

    return std::make_tuple(left, right, maxSum);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
Data findMaxCrossingSubarray(const std::vector<int>& v, int low, int mid, int high)
{
    int leftSum = std::numeric_limits<int>::min();
    int maxLeft = mid;
    int sum     = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += v[i];

        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = std::numeric_limits<int>::min();
    int maxRight = mid;
    sum          = 0;
    for(int i = mid + 1; i <= high; i++)
    {
        sum += v[i];

        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    //std::cout << std::endl << leftSum + rightSum;
    return Data(maxLeft, maxRight, leftSum + rightSum);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
Data findMaxSubarray(const std::vector<int>& v, int low, int high)
{
    if (low == high)
    {
        return Data(low, high, v[low]);
    }
    else
    {
        int mid    = (low + high) / 2;

        Data left  = findMaxSubarray(v, low, mid);
        Data right = findMaxSubarray(v, mid + 1, high);

        Data cross = findMaxCrossingSubarray(v, low, mid, high);

        if (left.sum > right.sum && left.sum> cross.sum)
        {
            return left;
        }

        if (right.sum > left.sum && right.sum > cross.sum)
        {
            return right;
        }

        if (cross.sum >= left.sum && cross.sum >= right.sum)
        {
            return cross;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    unsigned long size = 10000;
    int nrIterations   = 10;
    std::vector<int> v(size);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-20, 20);

    std::cout << std::endl << "Generating vector...";
    std::generate(v.begin(), v.end(), [&dist, &mt]()
    {
        return dist(mt);
    });
    std::cout << "done";

    int left, right, sum;

    auto start2 = std::chrono::system_clock::now();
    std::cout << std::endl << "Computing O(nlgn)...";
    for(int i = 0; i < nrIterations; i++)
    {
        findMaxSubarray(v, 0, v.size() -1);
    }
    auto duration2 = std::chrono::system_clock::now() - start2;
    std::cout << "done = " << std::chrono::duration_cast<std::chrono::milliseconds>(duration2).count();

    auto start1 = std::chrono::system_clock::now();
    std::cout << std::endl << "Computing O(n^2)...";
    for (int i = 0; i < nrIterations; i++)
    {
        findMaxSum(v);
    }
    auto duration1 = std::chrono::system_clock::now() - start1;
    std::cout << "done = " << std::chrono::duration_cast<std::chrono::milliseconds>(duration1).count();

    std::cout << std::endl << "\n\n";
    return 0;
}