#include "EfficientStack.h"

#include <iostream>


int main()
{
    EfficientStack stack;

    stack.push(2);
    stack.push(1);
    stack.push(3);
    stack.push(4);
    stack.push(0);
    stack.push(5);
    stack.push(6);
    stack.push(7);

    std::cout << std::endl << stack.getMin();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << std::endl << stack.getMin();


    std::cout << std::endl << "\n\n";
    return 0;
}