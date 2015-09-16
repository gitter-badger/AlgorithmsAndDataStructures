#pragma once

#include "ISort.h"


class OptimizedInsertionSort : public ISort
{
    public:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};