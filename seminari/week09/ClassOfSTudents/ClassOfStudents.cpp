#include "ClassOfStudents.h"

void ClassOfStudents::copyFrom(const ClassOfStudents& other) {
	currSize = other.currSize;
	cap = other.cap;
	students = new Student * [cap];
	for (size_t i = 0; i < cap; i++)
	{
		if (other.students[i]) {
			students[i] = other.students[i]->clone();
		}
	}
}

void ClassOfStudents::moveFrom(ClassOfStudents&& other) {
	students = other.students;
	other.students = nullptr;

	currSize = other.currSize;
	cap = other.cap;
	other.currSize = other.cap = 0;
}

void ClassOfStudents::free() {
	for (size_t i = 0; i < currSize; i++)
	{
		delete students[i];
	}
	delete[] students;
}

void ClassOfStudents::resize(int newCap) {
	Student** temp = new Student * [newCap];
	for (size_t i = 0; i < currSize; i++)
	{
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
	cap = newCap;
}

ClassOfStudents::ClassOfStudents() {
	students = new Student * [cap];
	for (int i = 0; i < cap; ++i) {
		students[i] = nullptr;
	}
}

ClassOfStudents::ClassOfStudents(const ClassOfStudents& other)
{
	copyFrom(other);
}

ClassOfStudents::ClassOfStudents(ClassOfStudents&& other) noexcept
{
	moveFrom(std::move(other));
}

ClassOfStudents& ClassOfStudents::operator=(const ClassOfStudents& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;

}

ClassOfStudents& ClassOfStudents::operator=(ClassOfStudents&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;

}

ClassOfStudents::~ClassOfStudents() {
	free();
}

size_t ClassOfStudents::findFirstFreeInd() const {
	for (size_t i = 0; i < cap; i++)
	{
		if (students[i]==nullptr)
		{
			return i;
		}
	}
	throw std::exception("No free indices");
}

void ClassOfStudents::insertAt(const Student& st, size_t ind) {
	if (ind>=cap)
	{
		resize(ind);
	}
	if (students[ind] == nullptr)
	{
		students[ind] = st.clone();
		currSize++;
	}
	else
	{
		*students[ind] = st;
	}
}

void ClassOfStudents::insertAt(Student&& st, size_t ind) {
	if (ind>=cap)
	{
		resize(ind);
	}
	if (students[ind]==nullptr)
	{
		students[ind] = new Student(std::move(st));
		currSize++;
	}
	else
	{
		*students[ind] = std::move(st);
	}
}

void ClassOfStudents::addStudent(const Student& st) {
	if (currSize>=cap)
	{
		resize(cap * 2);
	}
	size_t ind = findFirstFreeInd();
	insertAt(st, ind);
	
}

void ClassOfStudents::addStudent(Student&& st) {
	if (currSize>=cap)
	{
		resize(cap * 2);
	}
	size_t ind = findFirstFreeInd();
	insertAt(st, ind);
}

void ClassOfStudents::removeAt(size_t ind) {
	if (ind >= cap) {
		throw std::invalid_argument("No such ind");
	}
	delete students[ind];
	students[ind] = nullptr;
	currSize--;
}

void ClassOfStudents::print() const {
	for (size_t i = 0; i < cap; i++)
	{
		if (students[i])
		{
			(*students[i]).print();
		}
	}
}