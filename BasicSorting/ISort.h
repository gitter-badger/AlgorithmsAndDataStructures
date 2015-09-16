#pragma once

#include "Item.h"

#include <vector>


class ISort
{
    public:
        ISort(const std::vector<Item>& items);

        std::vector<Item> sort();

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) = 0;

    private:
        std::vector<Item> m_items;
};