#include "BubbleSort.h"


//======================================================================================================================
std::vector<Item> BubbleSort::sort(const std::vector<Item>& items, int left, int right)
{
    auto v = items;

    for (int i = left; i < right; i++)
    {
        for (int j = left; j < right - 1; j++)
        {
            if (v[j].getKey() > v[j+1].getKey())
            {
                std::swap(v[j], v[j+1]);
            }
        }
    }

    return v;
}
