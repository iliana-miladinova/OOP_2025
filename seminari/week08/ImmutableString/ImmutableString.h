#pragma once
#include "StringPool.h"
#include <iostream>

class ImmutableString {
private:
	const char* data;
	int size = 0;

	static StringPool pool;

	void free();
	void copyFrom(const ImmutableString& other);

public:
	ImmutableString(const char* str);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other);
	~ImmutableString();

	char operator[](size_t ind) const;

	size_t length() const;
	const char* c_str() const;

	friend bool operator==(const ImmutableString & lhs, const ImmutableString & rhs);
	friend std::ostream& operator<<(std::ostream & os, const ImmutableString & im);

	int getRefCount() const;
	static void print();
};

ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs);

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);