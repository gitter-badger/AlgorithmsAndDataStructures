#pragma once

#include <string>
#include <map>


class BaseConverter
{
    public:
        BaseConverter();

    //private:
        std::string fast_2_to_16(const std::string& number);
        std::string fast_16_to_2(const std::string& number);
        std::string fast_2_to_8(const std::string& number);
        std::string fast_8_to_2(const std::string& number);

    private:
        std::map<char, std::string> lookup_16_to_2;
        std::map<std::string, char> lookup_2_to_16;
};
