#pragma once

#include "ISort.h"


class ShellSort : public ISort
{
    public: 
        ShellSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};