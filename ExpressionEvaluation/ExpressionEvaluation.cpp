#include "ExpressionEvaluation.h"

#include <iostream>
#include <deque>


//==============================================================================================================================================
bool expression::isOperator(const char c)
{
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/') || c == '$');
}

//==============================================================================================================================================
bool expression::isUnary(const char c)
{
    //TODO: add next element to detect if it is -a or a - b
    return c == '$';
}

//==============================================================================================================================================
std::string expression::convertInfix2Postfix(const std::string& expression)
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
            float tempResult = 0;

            if(isUnary(c))
            {
                float n1 = numbers.top();
                numbers.pop();

                if(c == '-')
                {
                    tempResult = -n1;
                }

                if(c == '$')
                {
                    tempResult = std::sqrt(n1);
                }
            }
            else
            {
                float n1 = numbers.top();
                numbers.pop();

                float n2 = numbers.top();
                numbers.pop();


                if(c == '+')
                {
                    tempResult = n1 + n2;
                }

                if(c == '-')
                {
                    tempResult = n1 - n2;
                }

                if(c == '*')
                {
                    tempResult = n1 * n2;
                }

                if(c == '/')
                {
                    tempResult = n1 / n2;
                }
            }

            numbers.push(tempResult);
        }
    }

    result = numbers.top();
    return result;
}

//==============================================================================================================================================
std::string expression::convertPostfix2Infix(const std::string& expression)
{
    std::stack<std::string> infixExpression;

    for(const auto c : expression)
    {
        if(isdigit(c))
        {
            infixExpression.push(std::string(1, c));
        }

        if(isOperator(c))
        {
            std::string n1 = infixExpression.top();
            infixExpression.pop();

            std::string n2 = infixExpression.top();
            infixExpression.pop();

            std::string result = "(" + n1 + " " + std::string(1, c) + " " + n2 + ")";
            infixExpression.push(result);
        }
    }

    std::string result = infixExpression.top();
    return result;
}

//==============================================================================================================================================
std::string expression::removeRedundantParanthesis(const std::string& expression)
{
    std::string simplifiedExpression = "";

    std::stack<char> elements;

    for(const auto c : expression)
    {
        if(c != ')')
        {
            elements.push(c);
        }
        else
        {
            std::string tempExpression = "(";
            char nextChar;
            int distance = 0;
            do
            {
                nextChar = elements.top();
                elements.pop();

                tempExpression += nextChar;

                distance++;
            }
            while (nextChar != '(');

            if(distance != 1)
            {
                std::reverse(tempExpression.begin(), tempExpression.end());
                tempExpression = tempExpression.substr(0, tempExpression.length() - 1); // remove last  ')'
                tempExpression += ")";
                simplifiedExpression += tempExpression;
            }
        }
    }

    return simplifiedExpression;

}


