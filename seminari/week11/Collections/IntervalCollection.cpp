#include "IntervalCollection.h"

IntervalCollection::IntervalCollection(int start, int end) {
	if (end<start)
	{
		std::swap(start, end);
	}
	this->start = start;
	this->end = end;
	data = new int[end - start + 1] {0};
}

unsigned IntervalCollection::intervalLen() const {
	return end - start + 1;
}

void IntervalCollection::add(int num) {
	if (num<start || num>end) {
		throw std::invalid_argument("Num not in interval");
	}
	int ind = num - start;
	data[ind]++;
}

void IntervalCollection::remove(int num) {
	if (num<start || num>end) {
		throw std::invalid_argument("Num not in interval");
	}
	int ind = num - start;
	if (data[ind] == 0) {
		throw std::invalid_argument("No element to remove");
	}
	data[ind]--;
}

size_t IntervalCollection::count(int num) const {
	if (num<start || num>end) {
		throw std::invalid_argument("Num not in interval");
	}
	int ind = num - start;
	return data[ind];
}

bool IntervalCollection::contains(int num) const {
	return count(num) > 0;
}