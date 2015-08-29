#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<int> quick_sort(const std::vector<int>& v)
{
    if(v.size() == 1)
    {
        return v;
    }

    int x = v.front();

    std::vector<int> v1;
    std::copy_if(v.begin(), v.end(), std::back_inserter(v1), [x](int e)
    {
        return e < x;
    });

    std::vector<int> v2;
    std::copy_if(v.begin(), v.end(), std::back_inserter(v2), [x](int e)
    {
        return e > x;
    });

    auto v1_sort = quick_sort(v1);
    auto v2_sort = quick_sort(v2);

    std::vector<int> result;
    result.reserve(v1_sort.size() + v2_sort.size());

    result.insert(result.end(), v2_sort.begin(), v2_sort.end());
    result.insert(result.end(), v1_sort.begin(), v1_sort.end());

    return result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<int> mergesort(const std::vector<int>& v)
{
    if (v.size() == 1)
    {
        return v;
    }

    auto v1 = mergesort({v.begin(), v.begin() + v.size() / 2});
    auto v2 = mergesort({v.begin() + v.size() / 2, v.end()});

    std::vector<int> result;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

    return result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    std::vector<int> v {1, 3, 4, 21, 2, 3, 5, 7, 8, 1, 2, 0};
    //v = mergesort(v);
    v = quick_sort(v);

    for(int e : v)
    {
        std::cout << e << " ";
    }

    std::cout << std::endl << "\n\n";
    return 0;
}