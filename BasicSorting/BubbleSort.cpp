#include "BubbleSort.h"


//======================================================================================================================
BubbleSort::BubbleSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void BubbleSort::sort(std::vector<Item>& items, int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = left; j < right - 1; j++)
        {
            if (items[j].getKey() > items[j+1].getKey())
            {
                std::swap(items[j], items[j+1]);
            }
        }
    }
}
