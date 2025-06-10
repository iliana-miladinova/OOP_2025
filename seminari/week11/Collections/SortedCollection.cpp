#include "SortedCollection.h"

int SortedCollection::lowerBound(int num) const {
	int left = 0;
	int right = size - 1;
	int ind = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (data[mid] == num) {
			ind = mid;
			right = mid - 1;
		}
		else if (data[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ind;
}

int SortedCollection::upperBound(int num) const {
	int left = 0;
	int right = size - 1;
	int ind = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (data[mid] == num) {
			ind = mid;
			left = mid + 1;
		}
		else if (data[mid] > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ind;
}

void SortedCollection::add(int num) {
	if (size == cap) {
		resize(cap * 2);
	}

	int ind = size;
	while (ind != 0 && data[ind - 1] > num) {
		data[ind] = data[ind - 1];
		ind--;
	}
	data[ind] = num;
	size++;
}

void SortedCollection::remove(int num) {
	int ind = lowerBound(num);
	if (ind == -1) {
		throw std::invalid_argument("Invalid number to remove");
	}

	for (size_t i = ind; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

size_t SortedCollection::count(int num) const {
	int left = lowerBound(num);
	if (left == -1) {
		return 0;
	}
	int right = upperBound(num);
	return right - left + 1;
}

bool SortedCollection::contains(int num) const {
	return lowerBound(num) != -1;
}

PureNumbersCollection* SortedCollection::clone() const {
	return new SortedCollection(*this);
}

