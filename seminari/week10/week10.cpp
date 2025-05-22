// week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "SortedStudentDB.h"
#include "FilteredStudentDB.h"

bool isInCourse3(const Student& s) {
	return s.getYear() == 3;
}
bool cmpByName(const Student& a, const Student& b) {
	return strcmp(a.getName().c_str(), b.getName().c_str()) < 0;
}

bool cmpByFn(const Student& a, const Student& b) {
	return a.getFn() < b.getFn();
}

int main() {
	/*SortedStudentDB db;
	db.add(Student("Ivan", 12345, 2));
	db.add(Student("Petar", 54321, 1));
	db.add(Student("Georgi", 22222, 3));

	std::cout << "Before sorting:\n";
	db.display();

	db.sortBy(cmpByName);
	std::cout << "Sorted by name:\n";
	db.display();

	db.sortBy(cmpByFn);
	std::cout << "Sorted by FN:\n";
	db.display();*/

	FilteredStudentDB db;
	db.add(Student("Ivan", 12345, 2));
	db.add(Student("Petar", 54321, 3));
	db.add(Student("Georgi", 22222, 3));
	db.add(Student("Maria", 99999, 1));

	std::cout << "Before filtering:\n";
	db.display();

	db.filter(isInCourse3);
	std::cout << "Only course 3:\n";
	db.display();

	db.limit(1);
	std::cout << "Only first student:\n";
	db.display();


	return 0;

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
