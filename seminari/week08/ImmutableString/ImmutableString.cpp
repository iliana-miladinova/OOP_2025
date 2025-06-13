#include "ImmutableString.h"
#pragma warning(disable:4996)

StringPool ImmutableString::pool;

void ImmutableString::free() {
	pool.removeString(data);
}

void ImmutableString::copyFrom(const ImmutableString& other) {
	data = pool.getString(other.data);
	size = strlen(data);
}

ImmutableString::ImmutableString(const char* str) {
	data = pool.getString(str);
	size = strlen(data);
}

ImmutableString::ImmutableString(const ImmutableString& other) {
	copyFrom(other);
}

ImmutableString& ImmutableString::operator=(const ImmutableString& other) {
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ImmutableString::~ImmutableString() {
	free();
}

char ImmutableString::operator[](size_t ind) const {
	if (ind < 0 || ind >= size) {
		throw std::invalid_argument("Invalid ind");
	}
	return data[ind];
}

const char* ImmutableString::c_str() const {
	return data;
}

size_t ImmutableString::length() const {
	return size;
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs) {
	return lhs.data == rhs.data;
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& im) {
	os << im.data;
	return os;
}

ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs) {
	char* temp = new char[lhs.length() + rhs.length() + 1];
	strcpy(temp, lhs.c_str());
	strcat(temp, rhs.c_str());
	ImmutableString res(temp);

	delete[] temp;
	return res;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

int ImmutableString::getRefCount() const {
	return pool.getRefCount(data);
}

void ImmutableString::print() {
	return pool.print();
}