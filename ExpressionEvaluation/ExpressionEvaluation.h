#pragma once

#include <stack>
#include <sstream>
#include <string>


namespace expression
{
bool isOperator(const char c);

bool isUnary(const char c);

std::string convertInfix2Postfix(const std::string& expression);

std::string convertPostfix2Infix(const std::string& expression);

std::string removeRedundantParanthesis(const std::string& expression);

float evaluate(const std::string& infixExpression);
}