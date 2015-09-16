#pragma once

#include "Item.h"

#include <vector>


namespace utils
{
    bool isSorted(const std::vector<Item>& items);
    void viewKeys(const std::vector<Item>& items);
    void viewData(const std::vector<Item>& items);
}