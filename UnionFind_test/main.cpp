#include "../FirstExample/QuickUnionAlgorithm.h"
#include "../FirstExample/QuickFindAlgorithm.h"
#include "../FirstExample/IUnionFind.h"
#include "../FirstExample/UninonFindTemplate.h"

#include <gtest/gtest.h>

#include <iostream>
#include <memory>


//==============================================================================================================================================
void testPairProperties(IUninonFind* algorithm)
{
    algorithm->Initialize();

    // reflexivity
    EXPECT_TRUE(algorithm->addPair(1, 2));
    EXPECT_FALSE(algorithm->addPair(2, 1));

    // symmetry
    EXPECT_FALSE(algorithm->addPair(1, 1));

    // transitivity
    EXPECT_TRUE(algorithm->addPair(3, 4));
    EXPECT_TRUE(algorithm->addPair(4, 5));
    EXPECT_FALSE(algorithm->addPair(3, 5));
}

//==============================================================================================================================================
void testAlgorithm(IUninonFind* algorithm)
{
    algorithm->Initialize();

    EXPECT_TRUE(algorithm->addPair(3, 4));
    EXPECT_TRUE(algorithm->addPair(4, 9));
    EXPECT_TRUE(algorithm->addPair(8, 0));
    EXPECT_TRUE(algorithm->addPair(2, 3));
    EXPECT_TRUE(algorithm->addPair(5, 6));
    EXPECT_FALSE(algorithm->addPair(2, 9));
    EXPECT_TRUE(algorithm->addPair(5, 9));
    EXPECT_TRUE(algorithm->addPair(7, 3));
    EXPECT_FALSE(algorithm->addPair(7, 4));
    EXPECT_FALSE(algorithm->addPair(7, 4));
    EXPECT_FALSE(algorithm->addPair(3, 4));
}

//==============================================================================================================================================
TEST(UnionFind, quickFind)
{
    const int nrNodes = 10;
    std::unique_ptr<IUninonFind> algorithm = std::make_unique<QuickFindAlgorithm>(nrNodes);

    testPairProperties(algorithm.get());
    testAlgorithm(algorithm.get());
}

//==============================================================================================================================================
TEST(UnionFind, quickUnion)
{
    const int nrNodes = 10;
    std::unique_ptr<IUninonFind> algorithm = std::make_unique<QuickUnionAlgorithm>(nrNodes);

    testPairProperties(algorithm.get());
    testAlgorithm(algorithm.get());
}

//==============================================================================================================================================
TEST(UnionFind, weightedQuickUnion)
{

}

//==============================================================================================================================================
TEST(UnionFind, pathCompressionHalving)
{


}


