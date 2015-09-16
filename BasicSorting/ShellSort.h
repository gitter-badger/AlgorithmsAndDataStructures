#pragma once

#include "ISort.h"


class ShellSort : public ISort
{
    public:
        virtual void sort(std::vector<Item>& items, int left, int right) override;
};