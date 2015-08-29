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
int eval_prefix(const std::string& prefix, int& pos)
{
    char op = prefix[pos++];

    if (std::isdigit(op))
    {
        return op - '0';
    }

    int a = eval_prefix(prefix, pos);
    int b = eval_prefix(prefix, pos);

    return apply(op, a, b);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int eval2_prefix(const std::string& prefix, int& pos)
{
    char op = prefix[pos++];

    if(std::isdigit(op))
    {
        return op - '0';
    }

    return apply(op, eval_prefix(prefix, pos), eval_prefix(prefix, pos));
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int eval_postfix(const std::string& postfix, int& pos)
{
    char op = postfix[pos++];

    if (std::isdigit(op))
    {
        return eval_postfix(postfix, pos);
    }

    return apply(op, postfix[pos-1] - '0', postfix[pos-2] - '0');
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int pos = 0;
    std::cout << std::endl << eval_postfix("598+64**7+*", pos);

    std::cout << std::endl << "\n\n";
    return 0;
}