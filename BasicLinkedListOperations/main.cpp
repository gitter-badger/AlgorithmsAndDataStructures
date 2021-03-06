#include "LinkedList.h"
#include "Factory.h"
#include "Algorithm.h"

#include <iostream>
#include <iomanip>
#include <vector>


//==============================================================================================================================================================
void testSum()
{
    __int64 n1 = 9999;
    __int64 n2 = 999999999;
    LinkedList l1 = factory::create(n1);
    LinkedList l2 = factory::create(n2);
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
    auto list = factory::create(10);
    list.view();

    std::cout << "\n------\n";
    algorithm::remove(list, 0, 2);
    list.view();
}

//==============================================================================================================================================================
void testSeggregate()
{
    auto list = factory::create(10);
    algorithm::seggregateEvenOdds(list);
    list.view();
}

//==============================================================================================================================================================
void testRotate()
{
    auto list = factory::create(10);

    for (int i = 0 ; i < 10; i++)
    {
        std::cout << "\n";
        algorithm::rotateRight(list, 1);
        list.view();
    }
}

//==============================================================================================================================================================
void testPalindrome()
{
    LinkedList list;
    list.addBack(1);
    list.addBack(2);

    std::cout << "palindrome: " << algorithm::isPalindrom(list) << "\n";
}

//==============================================================================================================================================================
int main(int* argc, char** argw)
{
    //testSum();
    //testDelete();
    //testSetOperation();
    testSeggregate();
    //testRotate();
    //testPalindrome();

    return 0;
}