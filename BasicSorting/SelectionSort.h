#pragma once

#include "ISort.h"


class SelectionSort : public ISort
{
    public:
        SelectionSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};