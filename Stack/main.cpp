#include "IStack.h"
#include "ArrayStack.h"
#include "LinkedListStack.h"

#include <iostream>
#include <string>
#include <stack>


//================================================================================================================================================================================================================================================================
namespace convert
{
	int to_int(char ch)
	{
		if(isdigit(ch))
			return ch - '0'; // simple conversion of char -> int
		else
			return -1;
	}

	int compute(int a, int b, char operation)
	{
		int result = 0;

		if(operation == '+')
			result = a + b;

		if(operation == '-')
			result = a - b;

		if(operation == '*')
			result = a * b;

		if(operation == '/')
			result = a / b;

		return result;
	}
}

//================================================================================================================================================================================================================================================================
std::string infixToPostfix(const std::string& infixExpression)
{
	std::stack<char> expression;
	for(auto ch : infixExpression)
	{
		if(ch == ')')
		{
			std::cout << " " << expression.top();
			expression.pop();
		}

		if(ch == '*' || ch == '/' || ch == '-' || ch == '+')
			expression.push(ch);

		if(isdigit(ch))
			std::cout << " " << ch;
	}

	return "none";
}

//================================================================================================================================================================================================================================================================
int evaluatePostfixExpression(const std::string& expression)
{
	//ArrayStack stack(expression.size() + 1);
	LinkedListStack stack;

	for(auto ch : expression)
		if(isdigit(ch))
			stack.push(convert::to_int(ch));
		else
			stack.push(convert::compute(stack.pop(), stack.pop(), ch));

	return stack.top();
}

//================================================================================================================================================================================================================================================================
int main()
{
	std::cout << std::endl << evaluatePostfixExpression("598+46**7+*");

	//infixToPostfix("5*(((9+8)*(4*6))+7)");

	return 0;
}