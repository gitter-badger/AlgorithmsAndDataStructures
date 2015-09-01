#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

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
        left    = i;

        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];

            if(sum > maxSum)
            {
                maxSum = sum;
                right = j;
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
    for(int i = mid + 1; i < high; i++)
    {
        sum += v[i];

        if(sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

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
    std::vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int left, right, sum;

    std::tie(left, right, sum) = findMaxSum(v);
    std::cout << std::endl << "O(n^2) Max sum " << "[" << left << ", " << right << "] = " << sum;

    Data data = findMaxSubarray(v, 0, v.size());
    std::cout << std::endl << "O(nlgn) Max sum " << "[" << data.low << ", " << data.high << "] = " << data.sum;

    std::cout << std::endl << "\n\n";
    return 0;
}