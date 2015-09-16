#include "BogoSort.h"
#include "Utils.h"

#include <algorithm>
#include <iostream>


//======================================================================================================================
BogoSort::BogoSort(const std::vector<Item>& items) : ISort(items), m_randomEngine(m_randomDevice())
{

}

//======================================================================================================================
void BogoSort::sort(std::vector<Item>& items, int left, int right)
{
    int nrAtempts = 0;

    while (!utils::isSorted(items))
    {
        nrAtempts++;
        std::shuffle(items.begin(), items.end(), m_randomEngine);
    }

    std::cout << std::endl << "Sorted after nrAtempts = " << nrAtempts << "\n";
}
