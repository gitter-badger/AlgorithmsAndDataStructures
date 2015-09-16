#pragma once

#include "ISort.h"


class OptimizedBubbleSort : public ISort
{
    public: 
        OptimizedBubbleSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};