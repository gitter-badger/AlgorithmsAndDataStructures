#pragma once

#include <string>


class Item
{
    public:
        Item(const std::string& data, int key);

        int getKey() const;

        std::string getData() const;

    private:
        int         m_key;
        std::string m_data;
};