#include "Student.h"

Student::Student():name(""), fn(0), year(1) {

}

Student::Student(const MyString& name, unsigned fn, unsigned year) : name(name), fn(fn), year(year) {

}

const MyString& Student::getName() const {
	return name;
}

unsigned Student::getFn() const {
	return fn;
}

unsigned Student::getYear() const {
	return year;
}

void Student::print() const {
	std::cout << name << " " << fn << " " << year << std::endl;
}