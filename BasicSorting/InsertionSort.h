#pragma once

#include "ISort.h"


class InsertionSort : public ISort
{
    public:
        InsertionSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};