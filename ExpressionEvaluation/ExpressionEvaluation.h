#pragma once

#include <stack>
#include <sstream>
#include <string>


namespace expression
{
bool isOperator(const char c);

bool isUnary(const char c);

std::string convertInfixToPostfix(const std::string expression);

float evaluate(const std::string& infixExpression);
}