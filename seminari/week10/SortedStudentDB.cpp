#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(bool(*cmp)(const Student& lhs, const Student& rhs)) {
	for (int i = 0; i < currCount - 1; i++)
	{
		for (int j = 0; j < currCount - i -1; j++)
		{
			if (!cmp(students[j], students[j + 1])) {
				std::swap(students[j], students[j + 1]);
			}
		}
	}
}