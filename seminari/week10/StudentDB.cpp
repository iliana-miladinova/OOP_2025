#include "StudentDB.h"

void StudentDB::resize(unsigned newCap) {
	Student* temp = new Student[newCap];
	for (int i = 0; i < currCount; i++) {
		temp[i] = students[i];
	}
	delete[] students;
	cap = newCap;
	students = temp;
}

void StudentDB::copyFrom(const StudentDB& other) {
	currCount = other.currCount;
	cap = other.cap;
	students = new Student[cap];
	for (int i = 0; i < currCount; i++)
	{
		students[i] = other.students[i];
	}
}

void StudentDB::moveFrom(StudentDB&& other) {
	students = other.students;
	other.students = nullptr;
	currCount = other.currCount;
	cap = other.cap;
	other.currCount = other.cap = 0;
}

void StudentDB::free() {
	delete[] students;
}

StudentDB::StudentDB() {
	students = new Student[cap];
}

StudentDB::StudentDB(const StudentDB& other) {
	copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;

}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

StudentDB::~StudentDB() {
	free();
}

void StudentDB::add(const Student& st) {
	if (currCount == cap) {
		resize(cap * 2);
	}
	students[currCount++] = st;
}

void StudentDB::remove(unsigned fn) {
	for (int i = 0; i < currCount; i++)
	{
		if (students[i].getFn() == fn) {
			std::swap(students[i], students[currCount - 1]);
			currCount--;
			break;
		}
	}
}

const Student& StudentDB::find(unsigned fn) const {
	for (int i = 0; i < currCount; i++)
	{
		if (students[i].getFn() == fn) {
			return students[i];
		}
	}
	throw std::exception("No such student");
}

void StudentDB::display() const {
	for (int i = 0; i < currCount; i++)
	{
		students[i].print();
	}
}