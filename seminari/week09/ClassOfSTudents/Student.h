#pragma once
#include <iostream>
#include "MyString.h"

class Student {
private:
	MyString name;
	int age;
	
public:
	Student(const MyString& name, int age);
	Student(MyString&& name, int age);
	const MyString& getName() const;
	int getAge() const;
	Student* clone() const;

	void print() const;
};