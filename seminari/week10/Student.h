#pragma once
#include <iostream>
#include "MyString.h"

class Student {
public:
	Student();
	Student(const MyString& name, unsigned fn, unsigned year);

	const MyString& getName() const;
	unsigned getFn() const;
	unsigned getYear() const;

	void print() const;
private:
	MyString name;
	unsigned fn;
	unsigned year;
};