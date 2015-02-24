#include "LinkedList.h"
#include "Factory.h"
#include "Algorithm.h"

#include <iostream>
#include <iomanip>


//==============================================================================================================================================================
void testSum()
{
	__int64 n1 = 9999;
	__int64 n2 = 999999999;
	LinkedList l1 = factory::createFromNumber(n1);
	LinkedList l2 = factory::createFromNumber(n2);
	LinkedList l3 = algorithm::sum(l1, l2);

	std::cout << "list: ";
	l1.view();
	std::cout << " + ";
	l2.view();
	std::cout << " = ";
	l3.view();

	std::cout << "\nmath: ";
	std::cout << n1 << " + " << n2 << " = " << n1 + n2;
}

//==============================================================================================================================================================
void testDelete()
{
	auto list = factory::createFromIncreasingN(10);
	list.view();

	std::cout << "\n------\n";
	algorithm::remove(list, 0, 2);
	list.view();
}

//==============================================================================================================================================================
void testSetOperation()
{
	LinkedList l1;
	l1.addBack(1);
	l1.addBack(2);
	l1.addBack(3);

	LinkedList l2;
	l2.addBack(0);
	l2.addBack(1);
	l2.addBack(2);
	l2.addBack(4);

	std::cout << "List1 = ";
	l1.view();

	std::cout << "\nList2 = ";
	l2.view();

	auto result1 = algorithm::Union(l1, l2);
	std::cout << "\nUnion = ";
	result1.view();

	auto result2 = algorithm::Intersection(l1, l2);
	std::cout << "\nIntersection = ";
	result2.view();

	auto result3 = algorithm::Difference(l1, l2);
	std::cout << "\nDifference = ";
	result3.view();
}

//==============================================================================================================================================================
int main()
{
	testSetOperation();

    std::cout << std::endl << "\n\n";
    return 0;
}