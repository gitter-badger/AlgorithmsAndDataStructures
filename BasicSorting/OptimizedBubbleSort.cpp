#include "OptimizedBubbleSort.h"


//======================================================================================================================
OptimizedBubbleSort::OptimizedBubbleSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void OptimizedBubbleSort::sort(std::vector<Item>& items, int left, int right)
{
    bool sorted = false;

    for (size_t i = left; i < right && !sorted; i++)
    {
        sorted = true;

        for (size_t j = right - 1; j > left; j--)
        {
            if (items[j].getKey() < items[j-1].getKey())
            {
                std::swap(items[j], items[j-1]);
                sorted = false;
            }
        }
    }
}
