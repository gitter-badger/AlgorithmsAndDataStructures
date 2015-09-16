#include "InsertionSort.h"


//======================================================================================================================
InsertionSort::InsertionSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void InsertionSort::sort(std::vector<Item>& items, int left, int right)
{
    for (size_t i = left; i < right; i++)
    {
        for (size_t j = i; j > left; j--)
        {
            if (items[j].getKey() < items[j-1].getKey())
            {
                std::swap(items[j], items[j-1]);
            }
        }
    }
}
