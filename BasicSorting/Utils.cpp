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
bool isStable(const std::vector<Item>& before, const std::vector<Item>& after)
{
    std::vector<const Item*> beforeIndex;
    for(const auto& i : before)
    {
        beforeIndex.push_back(&i);
    }

    std::vector<const Item*> afterIndex;
    for(const auto& i : after)
    {
        afterIndex.push_back(&i);
    }

    for (size_t i = 0; i < after.size() - 1; i++)
    {
        if (after[i].getKey() == after[i+1].getKey())
        {
            int beforeDistance = findPosition(beforeIndex, &before[i]) - findPosition(beforeIndex, &before[i+1]);
            int afterDistacen  = findPosition(afterIndex, &after[i])   - findPosition(afterIndex, &after[i+1]);

            if (beforeDistance != afterDistacen)
            {
                return false;
            }
        }
    }

    return true;
}

//======================================================================================================================
int findPosition(const std::vector<const Item*>& items, const Item* item)
{
    auto it = std::find(items.begin(), items.end(), item);
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