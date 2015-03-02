#include "ExpressionEvaluation.h"


//==============================================================================================================================================
bool expression::isOperator(const char c)
{
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

//==============================================================================================================================================
std::string expression::convertInfixToPostfix(const std::string expression)
{
    std::stringstream result;
    std::stack<char> operators;

    for(const auto c : expression)
    {
        if(isdigit(c))
        {
            result << c;
        }

        if(isOperator(c))
        {
            operators.push(c);
        }

        if(c == ')')
        {
            result << operators.top();
            operators.pop();
        }
    }

    while(!operators.empty())
    {
        result << operators.top();
        operators.pop();
    }

    return result.str();
}

//==============================================================================================================================================
float expression::evaluate(const std::string& infixExpression)
{
    float result;
    std::stack<float> numbers;

    for(const auto c : infixExpression)
    {
        if(isdigit(c))
        {
            numbers.push(c - '0');
        }

        if(isOperator(c))
        {
            float n1 = numbers.top();
            numbers.pop();

            float n2 = numbers.top();
            numbers.pop();

            float tempResult = 0;

            if(c == '+')
            {
                tempResult = n1 + n2;
            }

            if(c == '*')
            {
                tempResult = n1 * n2;
            }

            numbers.push(tempResult);
        }
    }

    result = numbers.top();
    return result;
}
