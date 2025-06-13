#pragma once
#include <iostream>

class StringPool {
private:
	struct StringRecord {
		char* str = nullptr;
		int refCount = 0;
	};

	StringRecord* records = nullptr;
	int size = 0;
	int cap = 8;

	void free();
	void resize(int newCap);

	void allocateString(const char* str);
	int findString(const char* str) const;
	void removeRecord(int ind);
public:
	StringPool();
	const char* getString(const char* str);
	void removeString(const char* string);

	int getRefCount(const char* str);

	void print() const;

	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();
};