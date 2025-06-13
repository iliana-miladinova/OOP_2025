#include "Student.h"

Student::Student(const MyString& name, int age) :name(name), age(age) {

}

Student::Student(MyString&& name, int age) :name(std::move(name)), age(std::move(age)) {

}

const MyString& Student::getName() const {
	return name;
}

int Student::getAge() const {
	return age;
}

Student* Student::clone() const {
	return new Student(*this);
}

void Student::print() const {
	std::cout << name << " " << age << std::endl;
}