// Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bitset.h"
#include "SetByCriteria.h"

bool isEven(unsigned num) {
	return num % 2 == 0;
}

int main()
{
	Bitset s1(1024);

	s1.add(1);
	s1.add(10);
	s1.add(5);
	s1.print();

	Bitset s2(1024);

	s2.add(1);

	s2.add(17);
	s2.add(130);
	s2.print();


	Bitset intersect = UnionOfSets(s1, s2);
	Bitset uni = IntersectionOfSets(s1, s2);

	intersect.print();
	uni.print();

	SetByCriteria even(28, isEven);
	even.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
