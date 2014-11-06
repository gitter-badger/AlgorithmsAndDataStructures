#include "IStack.h"
#include "ArrayStack.h"

#include <iostream>
#include <string>

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

	int evaluate(int a, int b, char operation)
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
int evaluatePostfixExpression(const std::string& expression)
{
	ArrayStack stack(expression.size());

	for(auto ch : expression)
		if(isdigit(ch))
			stack.push(convert::to_int(ch));
		else
			stack.push(convert::evaluate(stack.pop(), stack.pop(), ch));

	return stack.top();
}

//================================================================================================================================================================================================================================================================
int main()
{
	std::cout << std::endl << evaluatePostfixExpression("598+46**7+*");

	return 0;
}