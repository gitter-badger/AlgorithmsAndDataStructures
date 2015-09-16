#pragma once

#include "Item.h"

#include <vector>


class ISort
{
    public:
        virtual std::vector<Item> sort(const std::vector<Item>& items, int left, int right) = 0;
};