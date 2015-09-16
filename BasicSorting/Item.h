#pragma once

#include <string>


class Item
{
    public:
        Item(int data, int key);

        int getKey() const;

        int getData() const;

    private:
        int m_key;
        int m_data;
};