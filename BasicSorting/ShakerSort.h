#pragma once

#include "ISort.h"


class ShakerSort : public ISort
{
    public:
        ShakerSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};