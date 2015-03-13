#include "../ExpressionEvaluation/ExpressionEvaluation.h"

#include <gtest/gtest.h>

#include <iostream>


//==============================================================================================================================================
TEST(ExpressionEvaluation, Infix2Postfix)
{
    EXPECT_EQ(expression::convertInfix2Postfix("( 5 * ( ((9+8) * (4*6)) + 7) )"), std::string("598+46**7+*"));
    EXPECT_EQ(expression::convertInfix2Postfix("( 1 + 2 + 3 + 4 )"),              std::string("1234+++"));
}

//==============================================================================================================================================
TEST(ExpressionEvaluation, Postfix2Infix)
{
    EXPECT_EQ(expression::convertPostfix2Infix("598+46**7+*"), std::string("((7 + ((6 * 4) * (8 + 9))) * 5)"));
    EXPECT_EQ(expression::convertPostfix2Infix("1234+++"),     std::string("(((4 + 3) + 2) + 1)"));
}

//==============================================================================================================================================
TEST(ExpressionEvaluation, MultipleConversion)
{
    std::string expression = "( 5 * ( ((9+8) * (4*6)) + 7) )";

    expression = expression::convertInfix2Postfix(expression);
    expression = expression::convertPostfix2Infix(expression);
    expression = expression::convertInfix2Postfix(expression);

    EXPECT_FLOAT_EQ(expression::evaluate(expression), 2075.0f);
}

//==============================================================================================================================================
TEST(ExpressionEvaluation, PostfixEvaluation)
{
    std::string e1 = expression::convertInfix2Postfix("( 5*(((9+8)*(4*6))+7) )");
    std::string e2 = expression::convertInfix2Postfix("( 0 * ((2+2) * (3+3)) )");
    std::string e3 = expression::convertInfix2Postfix("( 1 + 2 + 3 + 4 )");
    std::string e4 = expression::convertInfix2Postfix("( 1 + 2 + 3 + 4  + 2 * (2 + 2) )");

    EXPECT_FLOAT_EQ(expression::evaluate(e1), 2075.0f);
    EXPECT_FLOAT_EQ(expression::evaluate(e2), 0.0f);
    EXPECT_FLOAT_EQ(expression::evaluate(e3), 10.0f);
}