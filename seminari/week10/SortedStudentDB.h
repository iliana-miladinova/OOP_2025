#pragma once
#include "StudentDB.h"

class SortedStudentDB :public StudentDB {
public:
	void sortBy(bool (*cmp)(const Student& lhs, const Student& rhs));
};