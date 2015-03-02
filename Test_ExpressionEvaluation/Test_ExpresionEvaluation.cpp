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
        Assert::AreEqual(expression::convertInfixToPostfix("( 5 * ( ((9+8) * (4*6)) + 7) )"), std::string("598+46**7+*"));
        Assert::AreEqual(expression::convertInfixToPostfix("( 1 + 2 + 3 + 4 )"), std::string("1234+++"));
    }

    //==============================================================================================================================================
    TEST_METHOD(PostfixEvaluation)
    {
        std::string e1 = expression::convertInfixToPostfix("( 5*(((9+8)*(4*6))+7) )");
        std::string e2 = expression::convertInfixToPostfix("( 0 * ((2+2) * (3+3)) )");
        std::string e3 = expression::convertInfixToPostfix("( 1 + 2 + 3 + 4 )");
        std::string e4 = expression::convertInfixToPostfix("( 1 + 2 + 3 + 4  + 2 * (2 + 2) )");

        Assert::AreEqual(expression::evaluate(e1), 2075.0f);
        Assert::AreEqual(expression::evaluate(e2), 0.0f);
        Assert::AreEqual(expression::evaluate(e3), 10.0f);
    }

};
}