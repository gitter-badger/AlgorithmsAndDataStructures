#include "OptimizedInsertionSort.h"


//======================================================================================================================
OptimizedInsertionSort::OptimizedInsertionSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void OptimizedInsertionSort::sort(std::vector<Item>& items, int left, int right)
{
    // move smallest sentinel to first position
    for (size_t i = right - 1; i > left; i--)
    {
        if (items[i].getKey() < items[i-1].getKey())
        {
            std::swap(items[i], items[i-1]);
        }
    }

    for (size_t i = left + 1; i < right; i++)
    {
        int j = i;
        Item current = items[i];

        while ( current.getKey() < items[j-1].getKey())
        {
            items[j] = items[j-1];
            j--;
        }

        items[j] = current;
    }
}
