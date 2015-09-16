#pragma once

#include "ISort.h"


class OptimizedInsertionSort : public ISort
{
    public:
        OptimizedInsertionSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};