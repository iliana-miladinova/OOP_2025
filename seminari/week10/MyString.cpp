#include "MyString.h"
#pragma warning(disable:4996)

static unsigned roundToPowOfTwo(unsigned n) {
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
	return std::max(roundToPowOfTwo(strLen + 1), 16u);
}

MyString::MyString(size_t strLen) {
	cap = dataToAllocByStrLen(strLen);
	data = new char[cap];
	data[0] = '\0';
}

void MyString::resize(size_t newCap) {
	char* resizedData = new char[newCap];
	strcpy(resizedData, data);
	delete[] data;
	data = resizedData;
	cap = newCap;
}

void MyString::copyFrom(const MyString& other) {
	cap = other.cap;
	currSize = other.currSize;
	data = new char[cap];
	strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other) {
	data = other.data;
	other.data = nullptr;
	cap = other.cap;
	currSize = other.currSize;
}

void MyString::free() {
	delete[] data;
	data = nullptr;
	cap = 0;
	currSize = 0;
}

MyString::MyString(const char* data) {
	currSize = strlen(data);
	cap = dataToAllocByStrLen(currSize);
	this->data = new char[cap];
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

MyString::MyString(MyString&& other) noexcept{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept{
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
	if (currSize + other.currSize + 1 > cap) {
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

std::istream& operator>>(std::istream& is, MyString& str) {
	char buff[1024];
	is >> buff;
	size_t buffLen = strlen(buff);
	if (buffLen > str.cap) {
		str.resize(buffLen);
	}
	strcpy(str.data, buff);
	str.currSize = buffLen;
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << str.c_str();
	return os;
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