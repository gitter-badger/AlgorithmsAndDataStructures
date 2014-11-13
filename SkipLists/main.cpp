#include <iostream>
#include "SkipList.h"


int main()
{
	SkipList skipList;
	for(int i = 0; i < 60; i++)
		skipList.insert(rand() % 100);

	skipList.view();

	return 0;
}