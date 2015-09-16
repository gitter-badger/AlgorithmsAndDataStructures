#include "ShakerSort.h";


//======================================================================================================================
ShakerSort::ShakerSort(const std::vector<Item>& items) : ISort(items)
{

}

//======================================================================================================================
void ShakerSort::sort(std::vector<Item>& items, int left, int right)
{
    bool sorted = false;

    do
    {
        sorted = true;

        for(size_t j = right - 1; j > left; j--)
        {
            if(items[j].getKey() < items[j - 1].getKey())
            {
                std::swap(items[j], items[j - 1]);
                sorted = false;
            }
        }

        for(size_t j = left; j < right - 1; j++)
        {
            if(items[j].getKey() > items[j + 1].getKey())
            {
                std::swap(items[j], items[j + 1]);
                sorted = false;
            }
        }

    }while(!sorted);
}

