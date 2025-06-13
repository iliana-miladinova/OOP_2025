#pragma once
#include "Student.h"

constexpr size_t MAX_CAP = 16;

class ClassOfStudents {
private:
	Student** students = nullptr;
	int currSize = 0;
	int cap = MAX_CAP;

	void copyFrom(const ClassOfStudents& other);
	void moveFrom(ClassOfStudents&& other);
	void free();

	void resize(int newCap);

	size_t findFirstFreeInd() const;
public:
	ClassOfStudents();

	ClassOfStudents(const ClassOfStudents& other);
	ClassOfStudents& operator=(const ClassOfStudents& other);
	ClassOfStudents(ClassOfStudents&& other) noexcept;
	ClassOfStudents& operator=(ClassOfStudents&& other) noexcept;

	~ClassOfStudents();

	void addStudent(const Student& st);
	void addStudent(Student&& st);
	void insertAt(const Student& st, size_t ind);
	void insertAt(Student&& st, size_t ind);
	void removeAt(size_t ind);

	void print() const;
};