#pragma once
#include "Collection.h"

class DynamicCollection :public Collection {
protected:
	int* data = nullptr;
	size_t size = 0;
	size_t cap = 8;
	void resize(size_t newCap);

private:
	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&& other);
	void free();

public:
	DynamicCollection();
	DynamicCollection(const DynamicCollection& other);
	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other) noexcept;
	DynamicCollection& operator=(DynamicCollection&& other) noexcept;
	~DynamicCollection();
};