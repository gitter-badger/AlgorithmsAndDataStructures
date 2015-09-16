#include "Utils.h"

#include <algorithm>


namespace utils
{

bool isSorted(const std::vector<Item>& items)
{
    return std::is_sorted(items.begin(), items.end(), [](const Item& a, const Item& b)
    {
        return a.getKey() < b.getKey();
    });
}

} // namespace utils