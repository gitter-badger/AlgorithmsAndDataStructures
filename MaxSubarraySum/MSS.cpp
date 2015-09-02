#include "MSS.h"

#include <limits>


//----------------------------------------------------------------------------------------------------------------------------------------------
std::tuple<int, int, int> method1::findMaxSum(const std::vector<int>& v, int low, int high)
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
Data method2::findMaxCrossingSubarray(const std::vector<int>& v, int low, int mid, int high)
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

    return Data(maxLeft, maxRight, leftSum + rightSum);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
Data method2::findMaxSum(const std::vector<int>& v, int low, int high)
{
    if (low == high)
    {
        return Data(low, high, v[low]);
    }
    else
    {
        int mid    = (low + high) / 2;

        Data left  = findMaxSum(v, low, mid);
        Data right = findMaxSum(v, mid + 1, high);

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
int method3::findMaxSum(const std::vector<int>& v, int low, int high)
{
    if (low == high)
    {
        return v[low];
    }
    else
    {
        int mid = (low + high) / 2;

        int sumLeft  = findMaxSum(v, low, mid);
        int sumRight = findMaxSum(v, mid + 1, high);

        Data cross = method2::findMaxCrossingSubarray(v, low, mid, high);

        return std::max(std::max(sumLeft, sumRight), cross.sum);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int method4::findMaxSum(const std::vector<int>& v, int low, int high)
{
    int maxSum = std::numeric_limits<int>::min();

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += v[k];
            }

            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}
