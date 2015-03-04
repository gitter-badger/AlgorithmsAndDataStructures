#include "ExpressionEvaluation.h"

#include <iostream>


//==============================================================================================================================================
int main()
{
    std::string expression = "((((1 - 2 + 4))) + 5)";

    std::cout << std::endl << expression;
    std::cout << std::endl << expression::removeRedundantParanthesis(expression);

    std::cout << std::endl << "\n\n";
    return 0;
}