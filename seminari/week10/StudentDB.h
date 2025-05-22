#pragma once
#include "Student.h"

class StudentDB {
protected:
	Student* students = nullptr;
	unsigned currCount = 0;
	unsigned cap = 3;
private:
	void resize(unsigned newCap);
	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
	void free();

public:
	StudentDB();

	StudentDB(const StudentDB& other);
	StudentDB& operator=(const StudentDB& other);

	StudentDB(StudentDB&& other) noexcept;
	StudentDB& operator=(StudentDB&& other) noexcept;

	~StudentDB();

	void add(const Student& st);
	void remove(unsigned fn);
	const Student& find(unsigned fn) const;
	void display() const;
};