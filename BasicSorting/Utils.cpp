#include "Utils.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include "OptimizedInsertionSort.h"
#include "OptimizedBubbleSort.h"
#include "BogoSort.h"

#include <algorithm>
#include <iostream>


namespace utils
{

//----------------------------------------------------------------------------------------------------------------------------------------------
bool isSorted(const std::vector<Item>& items)
{
    return std::is_sorted(items.begin(), items.end(), [](const Item& a, const Item& b)
    {
        return a.getKey() < b.getKey();
    });
}

//======================================================================================================================
bool isStable(const std::vector<Item>& before, const std::vector<Item>& after)
{
    for (size_t i = 0; i < after.size() - 1; i++)
    {
        if (after[i].getKey() == after[i+1].getKey())
        {
            int beforeDistance = findPosition(before, after[i]) - findPosition(before, after[i+1]);
            int afterDistance  = findPosition(after, after[i])  - findPosition(after, after[i+1]);

            if (sign(beforeDistance) != sign(afterDistance))
            {
                return false;
            }
        }
    }

    return true;
}

//======================================================================================================================
int findPosition(const std::vector<Item>& items, const Item& searchItem)
{
    auto it = std::find_if(items.begin(), items.end(), [searchItem](const Item& i)
    {
        return i.getData() == searchItem.getData();
    });

    return std::distance(items.begin(), it);
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
        case SortMethod::Bubble:     return std::make_shared<BubbleSort>(items);             break;
        case SortMethod::Insertion:  return std::make_shared<InsertionSort>(items);          break;
        case SortMethod::Selection:  return std::make_shared<SelectionSort>(items);          break;
        case SortMethod::Shaker:     return std::make_shared<ShakerSort>(items);             break;
        case SortMethod::Shell:      return std::make_shared<ShellSort>(items);              break;
        case SortMethod::OInsertion: return std::make_shared<OptimizedInsertionSort>(items); break;
        case SortMethod::OBubble:    return std::make_shared<OptimizedBubbleSort>(items);    break;
        case SortMethod::Bogo:       return std::make_shared<BogoSort>(items);               break;

        default:
            throw std::exception("Sorting method does not exist!");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int sign(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

} // namespace utils