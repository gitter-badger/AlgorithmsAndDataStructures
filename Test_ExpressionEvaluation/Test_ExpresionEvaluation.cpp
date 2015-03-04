#include "CppUnitTest.h"

#include "../ExpressionEvaluation/ExpressionEvaluation.h"
#include <CppUnitTestLogger.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Test_ExpressionEvaluation
{
TEST_CLASS(ExpressionEvaluation)
{
public:

    //==============================================================================================================================================
    TEST_METHOD(Infix2Postfix)
    {
        Assert::AreEqual(expression::convertInfix2Postfix("( 5 * ( ((9+8) * (4*6)) + 7) )"), std::string("598+46**7+*"));
        Assert::AreEqual(expression::convertInfix2Postfix("( 1 + 2 + 3 + 4 )"), std::string("1234+++"));
    }

    //==============================================================================================================================================
    TEST_METHOD(Postfix2Infix)
    {
        Assert::AreEqual(expression::convertPostfix2Infix("598+46**7+*"), std::string("((7 + ((6 * 4) * (8 + 9))) * 5)"));
        Assert::AreEqual(expression::convertPostfix2Infix("1234+++"), std::string("(((4 + 3) + 2) + 1)"));
    }

    //==============================================================================================================================================
    TEST_METHOD(MultipleConversion)
    {
        std::string expression = "( 5 * ( ((9+8) * (4*6)) + 7) )";

        expression = expression::convertInfix2Postfix(expression);
        expression = expression::convertPostfix2Infix(expression);
        expression = expression::convertInfix2Postfix(expression);

        Assert::AreEqual(expression::evaluate(expression), 2075.0f);
    }

    //==============================================================================================================================================
    TEST_METHOD(PostfixEvaluation)
    {
        std::string e1 = expression::convertInfix2Postfix("( 5*(((9+8)*(4*6))+7) )");
        std::string e2 = expression::convertInfix2Postfix("( 0 * ((2+2) * (3+3)) )");
        std::string e3 = expression::convertInfix2Postfix("( 1 + 2 + 3 + 4 )");
        std::string e4 = expression::convertInfix2Postfix("( 1 + 2 + 3 + 4  + 2 * (2 + 2) )");

        Assert::AreEqual(expression::evaluate(e1), 2075.0f);
        Assert::AreEqual(expression::evaluate(e2), 0.0f);
        Assert::AreEqual(expression::evaluate(e3), 10.0f);
    }

};
}