#include "IStack.h"
#include "ArrayStack.h"

#include <iostream>
#include <string>


int evaluatePostfixExpression(const std::string& expression)
{
	ArrayStack stack(expression.size());

	for(auto ch : expression)
	{
		if(isdigit(ch))
		{
			int nr = (int)(ch - '0');
			stack.push(nr);
		}
		else
		{
			int result;

			if(ch == '+')
				result = stack.pop() + stack.pop();

			if(ch == '-')
				result = stack.pop() - stack.pop();

			if(ch == '*')
				result = stack.pop() * stack.pop();

			if(ch == '/')
				result = stack.pop() / stack.pop();

			stack.push(result);
		}
	}

	return stack.top();
}



int main()
{
	std::cout << std::endl << evaluatePostfixExpression("598+46**7+*");

	return 0;
}