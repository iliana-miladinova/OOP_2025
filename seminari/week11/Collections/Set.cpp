#include "Set.h"
#include "NormalCollection.h"
#include "SortedCollection.h"

void Set::copyFrom(const Set& other) {
	collection = other.collection->clone();
}

void Set::moveFrom(Set&& other) {
	collection = other.collection;
	other.collection = nullptr;
}

void Set::free() {
	delete collection;
}

Set::Set(CollectionType type) {
	if (type==CollectionType::NORMAL_COLLECTION)
	{
		collection = new NormalCollection();
	}
	else if (type == CollectionType::SORTED_COLLECTION) {
		collection = new SortedCollection();
	}
}

Set::Set(const Set& other) {
	copyFrom(other);
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Set::Set(Set&& other) noexcept {
	moveFrom(std::move(other));
}

Set& Set::operator=(Set&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Set::~Set() {
	free();
}

void Set::add(int num) {
	if (!collection->contains(num)) {
		collection->add(num);
	}
}

void Set::remove(int num) {
	collection->remove(num);
}

size_t Set::count(int num) const {
	return collection->count(num);
}

bool Set::contains(int num) const {
	return collection->contains(num);
}