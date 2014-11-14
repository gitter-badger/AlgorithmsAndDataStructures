#include "Poly.h"



int main()
{
	Poly<int> poly1(2);
	poly1[0] = 1;
	poly1[1] = 2;
	poly1[2] = 10;

	Poly<int> poly2(3);
	poly2[0] = 1;
	poly2[1] = 2;
	poly2[2] = 10;
	poly2[3] = 5;

	poly1.view();
	poly2.view();

	auto result1 = poly1 + poly2;
	auto result2 = poly1 * poly2;
	result1.view();
	result2.view();


	std::cout << std::endl << std::endl;
	return 0;
}