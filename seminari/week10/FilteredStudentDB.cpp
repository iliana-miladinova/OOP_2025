#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(bool(*pred)(const Student& st)) {
	for (int i = 0; i < currCount; i++)
	{
		if (!pred(students[i])) {
			remove(students[i].getFn());
			i--;
		}
	}
}

void FilteredStudentDB::limit(unsigned n) {
	if (n >= currCount)
		return;

	currCount = n;
}