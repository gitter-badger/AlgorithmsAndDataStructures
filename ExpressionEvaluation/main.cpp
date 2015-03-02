#include "ExpressionEvaluation.h"

#include <iostream>


//==============================================================================================================================================
int main()
{
    std::string infix   = "( 9 - 1 - 2 - 3 )";
    std::string postfix = expression::convertInfixToPostfix(infix);

    std::cout << std::endl << "infix   = " << infix;
    std::cout << std::endl << "postfix = " << postfix;
    std::cout << std::endl << "result  = " << expression::evaluate(postfix);


    std::cout << std::endl << "\n\n";
    return 0;
}