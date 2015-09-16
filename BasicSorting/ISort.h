#pragma once

#include "Item.h"

#include <vector>


class ISort
{
    public:
        virtual void sort(std::vector<Item>& items, int left, int right) = 0;
};