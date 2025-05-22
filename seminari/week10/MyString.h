#pragma once
#include <iostream>
#include <cstring>

class MyString {
public:
	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	size_t len() const;
	const char* c_str() const;

	MyString& operator+=(const MyString& other);

	char& operator[](size_t ind);
	char operator[](size_t ind) const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream& is, MyString& str);
private:
	char* data = nullptr;
	size_t currSize = 0;
	size_t cap = 0;

	void resize(size_t newCap);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();

	explicit MyString(size_t strLen);
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);