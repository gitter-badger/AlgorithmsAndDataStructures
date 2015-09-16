#include "SelectionSort.h"


//======================================================================================================================
SelectionSort::SelectionSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void SelectionSort::sort(std::vector<Item>& items, int left, int right)
{
    for (size_t i = left; i < right; i++)
    {
        int min = i;
        for (size_t j = i; j < right; j++)
        {
            if (items[j].getKey() < items[min].getKey())
            {
                min = j;
            }
        }

        std::swap(items[i], items[min]);
    }
}
