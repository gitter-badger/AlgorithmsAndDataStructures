#include "BaseConverter.h"

#include <iostream>


int main()
{
    BaseConverter convert;


    std::cout << convert.fast_16_to_2("A2B1") << "\n";
    std::cout << convert.fast_2_to_16("1010001010110001") << "\n";


    return 0;
}