#include <iostream>
#include <string>
#include <cctype>


//----------------------------------------------------------------------------------------------------------------------------------------------
int apply(char op, int a, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default : throw std::exception("bad_operator");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int eval(const std::string& expression, int& position)
{
    char op = expression[position++];

    if (std::isdigit(op))
    {
        return op - '0';
    }

    int a = eval(expression, position);
    int b = eval(expression, position);

    return apply(op, a, b);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int eval2(const std::string& expression, int& position)
{
    char op = expression[position++];

    if(std::isdigit(op))
    {
        return op - '0';
    }

    return apply(op, eval(expression, position), eval(expression, position));
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int pos = 0;
    std::cout << std::endl << eval2("*+7**46+895", pos);

    std::cout << std::endl << "\n\n";
    return 0;
}