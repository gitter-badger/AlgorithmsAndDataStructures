#include "Utils.h"

#include <algorithm>
#include <iostream>


namespace utils
{

bool isSorted(const std::vector<Item>& items)
{
    return std::is_sorted(items.begin(), items.end(), [](const Item& a, const Item& b)
    {
        return a.getKey() < b.getKey();
    });
}

//======================================================================================================================
void viewKeys(const std::vector<Item>& items)
{
    for (const auto& item : items)
    {
        std::cout << item.getKey() << " ";
    }
}

//======================================================================================================================
void viewData(const std::vector<Item>& items)
{
    for (const auto& item : items)
    {
        std::cout << "\n";
        std::cout << item.getKey() << " -> " << item.getData();
    }
}

} // namespace utils