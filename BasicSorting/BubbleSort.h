#pragma once

#include "ISort.h"


class BubbleSort : public ISort
{
    public:
        BubbleSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};