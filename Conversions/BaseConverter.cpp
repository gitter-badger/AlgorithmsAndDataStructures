#include "BaseConverter.h"

#include <cassert>
#include <iostream>


//======================================================================================================================
BaseConverter::BaseConverter()
{
    lookup_16_to_2['0'] = "0000";
    lookup_16_to_2['1'] = "0001";
    lookup_16_to_2['2'] = "0010";
    lookup_16_to_2['3'] = "0011";
    lookup_16_to_2['4'] = "0100";
    lookup_16_to_2['5'] = "0101";
    lookup_16_to_2['6'] = "0110";
    lookup_16_to_2['7'] = "0111";
    lookup_16_to_2['8'] = "1000";
    lookup_16_to_2['9'] = "1001";
    lookup_16_to_2['A'] = "1010";
    lookup_16_to_2['B'] = "1011";
    lookup_16_to_2['C'] = "1100";
    lookup_16_to_2['D'] = "1101";
    lookup_16_to_2['E'] = "1110";
    lookup_16_to_2['F'] = "1111";

    lookup_2_to_16["0000"] = '0';
    lookup_2_to_16["0001"] = '1';
    lookup_2_to_16["0010"] = '2';
    lookup_2_to_16["0011"] = '3';
    lookup_2_to_16["0100"] = '4';
    lookup_2_to_16["0101"] = '5';
    lookup_2_to_16["0110"] = '6';
    lookup_2_to_16["0111"] = '7';
    lookup_2_to_16["1000"] = '8';
    lookup_2_to_16["1001"] = '9';
    lookup_2_to_16["1010"] = 'A';
    lookup_2_to_16["1011"] = 'B';
    lookup_2_to_16["1100"] = 'C';
    lookup_2_to_16["1101"] = 'D';
    lookup_2_to_16["1110"] = 'E';
    lookup_2_to_16["1111"] = 'F';
}

//======================================================================================================================
std::string BaseConverter::fast_16_to_2(const std::string& number)
{
    std::string result;
    for(const auto& c : number)
    {
        result += lookup_16_to_2[c];
    }

    return result;
}

//======================================================================================================================
std::string BaseConverter::fast_2_to_16(const std::string& number)
{
    assert(number.size() % 4 == 0);

    std::string result;
   
    for (int i = 0; i <= number.size()/4; i ++)
    {
        std::string group = number.substr(i * 4, 4);
        result += lookup_2_to_16[group];
    }

    return result;
}
