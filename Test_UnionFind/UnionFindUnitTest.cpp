#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\FirstExample\QuickUnionAlgorithm.h"
#include "..\FirstExample\QuickFindAlgorithm.h"
#include "..\FirstExample\IUnionFind.h"
#include "..\FirstExample\UninonFindTemplate.h"

#include <iostream>
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Test_UnionFind
{		
	TEST_CLASS(UnionFind)
	{
		public:
			TEST_METHOD(quickFind)
			{
				std::unique_ptr<IUninonFind> algorithm = std::make_unique<QuickFindAlgorithm>();
				testPairProperties(algorithm.get());
				testAlgorithm(algorithm.get());
			}

			TEST_METHOD(quickUnion)
			{
				std::unique_ptr<IUninonFind> algorithm = std::make_unique<QuickUnionAlgorithm>();
				testPairProperties(algorithm.get());
				testAlgorithm(algorithm.get());
			}

			TEST_METHOD(weightedQuickUnion)
			{
				
			}

			TEST_METHOD(pathCompressionHalving)
			{


			}

		private:
			void testPairProperties(IUninonFind* algorithm)
			{
				const int nrNodes = 10;
				algorithm->Initialize(nrNodes);

				// reflexivity
				Assert::IsTrue(algorithm->addPair(1, 2));
				Assert::IsFalse(algorithm->addPair(2, 1));

				// symmetry
				Assert::IsFalse(algorithm->addPair(1, 1));

				// transitivity
				Assert::IsTrue(algorithm->addPair(3, 4));
				Assert::IsTrue(algorithm->addPair(4, 5));
				Assert::IsFalse(algorithm->addPair(3, 5));
			}

			void testAlgorithm(IUninonFind* algorithm)
			{
				const int nrNodes = 10;
				algorithm->Initialize(nrNodes);

				Assert::IsTrue(algorithm->addPair(3, 4));
				Assert::IsTrue(algorithm->addPair(4, 9));
				Assert::IsTrue(algorithm->addPair(8, 0));
				Assert::IsTrue(algorithm->addPair(2, 3));
				Assert::IsTrue(algorithm->addPair(5, 6));
				Assert::IsFalse(algorithm->addPair(2, 9));
				Assert::IsTrue(algorithm->addPair(5, 9));
				Assert::IsTrue(algorithm->addPair(7, 3));
				Assert::IsFalse(algorithm->addPair(7, 4));
				Assert::IsFalse(algorithm->addPair(7, 4));
				Assert::IsFalse(algorithm->addPair(3, 4));
			}
	};
}