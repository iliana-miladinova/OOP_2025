#include "StringPool.h"
#pragma warning(disable:4996)

void StringPool::free() {
	for (size_t i = 0; i < cap; i++)
	{
		delete[] records[i].str;
	}
	delete[] records;
}

void StringPool::resize(int newCap) {
	StringRecord* temp = new StringRecord[newCap];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = records[i];
	}
	delete[] records;
	records = temp;
	cap = newCap;
}

void StringPool::allocateString(const char* str) {
	if (size == cap) {
		resize(cap * 2);
	}
	
	int len = strlen(str);
	records[size].str = new char[len + 1];
	strcpy(records[size].str, str);
	records[size].refCount = 1;
	size++;
}

int StringPool::findString(const char* str) const {
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(records[i].str,str)==0)
		{
			return i;
		}
	}
	return -1;
}

void StringPool::removeRecord(int ind) {
	std::swap(records[ind], records[size - 1]);
	delete[] records[size - 1].str;
	records[size - 1].str = nullptr;
	records[size - 1].refCount = 0;
	size--;
}

StringPool::StringPool() {
	records = new StringRecord[cap];
}

const char* StringPool::getString(const char* str) {
	int ind = findString(str);
	if (ind==-1)
	{
		allocateString(str);
		return records[size-1].str;
	}
	else
	{
		records[ind].refCount++;
		return records[ind].str;
	}
}

void StringPool::removeString(const char* str) {
	int ind = findString(str);
	records[ind].refCount--;
	if (records[ind].refCount==0)
	{
		removeRecord(ind);
	}
}

int StringPool::getRefCount(const char* str) {
	int ind = findString(str);
	return records[ind].refCount;
}

void StringPool::print() const {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << records[i].str << " " << records[i].refCount << std::endl;
	}
}

StringPool::~StringPool() {
	free();
}