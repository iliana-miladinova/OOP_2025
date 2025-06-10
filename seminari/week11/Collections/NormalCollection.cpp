#include "NormalCollection.h"

void NormalCollection::add(int num) {
	if (size==cap)
	{
		resize(cap * 2);
	}
	data[size++] = num;
}

int NormalCollection::findInd(int num) const {
	int ind = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (data[i]==num)
		{
			ind = i;
			break;
		}
	}
	return ind;
}

void NormalCollection::remove(int num) {
	int ind = findInd(num);
	if (ind==-1)
	{
		throw std::invalid_argument("This number is not in the collection");
	}
	for (size_t i = ind; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

size_t NormalCollection::count(int num) const {
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (data[i]==num)
		{
			count++;
		}
	}
	return count;
}

bool NormalCollection::contains(int num) const {
	//return count(num) > 0;
	return findInd(num) != -1;
}

PureNumbersCollection* NormalCollection::clone() const {
	return new NormalCollection(*this);
}