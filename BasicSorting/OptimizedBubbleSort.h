#pragma once

#include "ISort.h"


class OptimizedBubbleSort : public ISort
{
    public:
        virtual std::vector<Item> sort(const std::vector<Item>& items, int left, int right) override;
};