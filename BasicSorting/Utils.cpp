#include "Utils.h"
#include "BubbleSort.h"

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

//======================================================================================================================
std::shared_ptr<ISort> createSort(SortMethod method, const std::vector<Item>& items)
{
    switch (method)
    {
        case SortMethod::Bubble:     return std::make_shared<BubbleSort>(items); break;
        case SortMethod::Insertion:  return std::make_shared<BubbleSort>(items); break;
        case SortMethod::Selection:  return std::make_shared<BubbleSort>(items); break;
        case SortMethod::Shaker:     return std::make_shared<BubbleSort>(items); break;
        case SortMethod::Shell:      return std::make_shared<BubbleSort>(items); break;
        case SortMethod::OInsertion: return std::make_shared<BubbleSort>(items); break;
        case SortMethod::OBubble:    return std::make_shared<BubbleSort>(items); break;

        default:
            throw std::exception("Sorting method does not exist!");
    }
}

} // namespace utils