#pragma once

#include "Item.h"
#include "ISort.h"
#include "SortMethod.h"

#include <vector>
#include <memory>


namespace utils
{
    bool isSorted(const std::vector<Item>& items);
    void viewKeys(const std::vector<Item>& items);
    void viewData(const std::vector<Item>& items);

    std::shared_ptr<ISort> createSort(SortMethod method, const std::vector<Item>& items);
}