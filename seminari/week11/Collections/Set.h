#pragma once
#include "PureNumbersCollection.h"

enum class CollectionType {
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

class Set :public Collection {
private:
	PureNumbersCollection* collection;

	void copyFrom(const Set& other);
	void moveFrom(Set&& other);
	void free();
public:
	Set(CollectionType type);

	Set(const Set& other);
	Set& operator=(const Set& other);
	Set(Set&& other) noexcept;
	Set& operator=(Set&& other) noexcept;
	~Set();

	void add(int num) override;
	void remove(int num) override;
	size_t count(int num) const override;
	bool contains(int num) const override;
};