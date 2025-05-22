#pragma once
#include "StudentDB.h"

class FilteredStudentDB : public StudentDB {
public:
	void filter(bool(*pred)(const Student& st));
	void limit(unsigned n);
};
