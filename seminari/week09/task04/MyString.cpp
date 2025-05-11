#include "MyString.h"
#include <cstring>
#pragma warning(disable:4996)

static unsigned roundToPowerOfTwo(unsigned n) {
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}

static unsigned dataToAllocByStrLen(unsigned strLen) {
	return std::max(roundToPowerOfTwo(strLen + 1), 16u);
}

MyString::MyString(size_t strLen) {
	capacity = dataToAllocByStrLen(strLen);
	data = new char[capacity];
	data[0] = '\0';
}

void MyString::resize(size_t newCap) {
	char* resizedData = new char[newCap];
	strcpy(resizedData, data);
	delete[] data;
	data = resizedData;
	capacity = newCap;
}

void MyString::copyFrom(const MyString& other) {
	capacity = other.capacity;
	currSize = other.currSize;
	data = new char[capacity];
	strcpy(data, other.data);
}

void MyString::free() {
	delete[] data;
	data = nullptr;
	capacity = 0;
	currSize = 0;
}

void MyString::moveFrom(MyString&& other) {
	data = other.data;
	other.data = nullptr;
	capacity = other.capacity;
	currSize = other.currSize;
}

MyString::MyString(const char* data) {
	currSize = strlen(data);
	capacity = dataToAllocByStrLen(currSize);
	this->data = new char[capacity];
	strcpy(this->data, data);
}

MyString::MyString() :MyString("") {

}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept {
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString() {
	free();
}

size_t MyString::len() const {
	return currSize;
}

const char* MyString::c_str() const {
	return data;
}

MyString& MyString::operator+=(const MyString& other) {
	if (currSize + other.currSize + 1 > capacity) {
		resize(dataToAllocByStrLen(currSize + other.currSize));
	}
	strncpy(data, other.data, other.currSize);
	currSize += other.currSize;

	return *this;
}

char& MyString::operator[](size_t ind) {
	if (ind >= currSize) {
		throw std::out_of_range("Invalid ind");
	}
	return data[ind];
}

char MyString::operator[](size_t ind) const {
	if (ind >= currSize) {
		throw std::out_of_range("Invalid ind");
	}
	return data[ind];
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString newStr(lhs.currSize + rhs.currSize);
	newStr += lhs;
	newStr += rhs;
	return newStr;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str) {
	char buff[1024];
	is >> buff;
	size_t buffLen = strlen(buff);
	if (buffLen > str.capacity) {
		str.resize(dataToAllocByStrLen(buffLen));
	}
	strcpy(str.data, buff);
	str.currSize = buffLen;
	return is;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
	return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs) {
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs) {
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}