#include "ExpressionEvaluation.h"

#include <iostream>


//==============================================================================================================================================
int main(int argc, char** argv)
{
    std::string expression = "((((1 - 2 + 4))) + 5)";

    std::cout << std::endl << expression;
    std::cout << std::endl << expression::removeRedundantParanthesis(expression);
    std::cout << std::endl << "\n\n\n";


    std::cout << std::endl << expression::evaluate("598+64**7+*");
    return 0;
}