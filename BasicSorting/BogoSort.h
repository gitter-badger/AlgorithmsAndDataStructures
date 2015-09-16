#pragma once

#include "ISort.h"

#include <random>


class BogoSort : public ISort
{
    public:
        BogoSort(const std::vector<Item>& items);

    private:
        virtual void sort(std::vector<Item>& items, int left, int right) override;

    private:
        std::random_device m_randomDevice;
        std::mt19937       m_randomEngine;
};