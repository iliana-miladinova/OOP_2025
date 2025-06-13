// ClassOfSTudents.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "ClassOfStudents.h"

int main()
{
    /*MyString name = "St2";

    Student s1("St1", 12);

    Student s2(name, 12);

    ClassOfStudents students;
    students.addStudent(s1);

    students.addStudent({ "student1",15 });

    students.print();*/
    Student s1("Ivan", 16);
    ClassOfStudents group1;

    group1.addStudent(s1);
    group1.print();
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
