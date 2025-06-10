#include "DynamicCollection.h"

void DynamicCollection::copyFrom(const DynamicCollection& other) {
	size = other.size;
	cap = other.cap;
	data = new int[cap];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void DynamicCollection::moveFrom(DynamicCollection&& other) {
	data = other.data;
	other.data = nullptr;
	size = other.size;
	cap = other.cap;
	other.size = other.cap = 0;
}

void DynamicCollection::free() {
	delete[] data;
}

void DynamicCollection::resize(size_t newCap) {
	int* resized = new int[newCap];
	for (size_t i = 0; i < size; i++)
	{
		resized[i] = data[i];
	}
	delete[] data;
	data = resized;
	cap = newCap;
}

DynamicCollection::DynamicCollection() {
	data = new int[cap];
}

DynamicCollection::DynamicCollection(const DynamicCollection& other) {
	copyFrom(other);
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other) {
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicCollection::DynamicCollection(DynamicCollection&& other) noexcept {
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept {
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

DynamicCollection::~DynamicCollection() {
	free();
}