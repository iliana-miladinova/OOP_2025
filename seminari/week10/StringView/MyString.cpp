#include "MyString.h"
#include <cstring>
#pragma warning(disable: 4996)

static unsigned roundToPowerOfTwo(unsigned n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

MyString::MyString(size_t stringLength)
{
    allocatedDataCapacity = dataToAllocByStringLen(stringLength);
    data = new char[allocatedDataCapacity];
    data[0] = '\0';
}

void MyString::resize(size_t newAllocatedDataCapacity)
{
    char* resizedData = new char[newAllocatedDataCapacity];
    strcpy(resizedData, data);
    delete[] data;
    data = resizedData;
    allocatedDataCapacity = newAllocatedDataCapacity;
}

void MyString::free() {
    delete[] data;
    data = nullptr;
    currentSize = allocatedDataCapacity = 0;
}

void MyString::copyFrom(const MyString& other) {
    currentSize = other.currentSize;
    allocatedDataCapacity = other.allocatedDataCapacity;
    data = new char[allocatedDataCapacity];
    strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other) noexcept {
    currentSize = other.currentSize;
    allocatedDataCapacity = other.allocatedDataCapacity;
    data = other.data;
    other.data = nullptr;
    other.currentSize = other.allocatedDataCapacity = 0;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* str)
{
    currentSize = strlen(str);
    allocatedDataCapacity = dataToAllocByStringLen(currentSize);
    data = new char[allocatedDataCapacity];
    strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
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

MyString::~MyString()
{
    free();
}

size_t MyString::length() const {
    return currentSize;
}

const char* MyString::c_str() const {
    return data;
}

MyString& MyString::operator+=(const MyString& other) {
    if (currentSize + other.currentSize + 1 > allocatedDataCapacity) {
        resize(currentSize + other.currentSize);
    }

    strncat(data, other.data, other.currentSize);
    currentSize += other.currentSize;
    return *this;
}

char& MyString::operator[](size_t index) {
    return data[index];
}

char MyString::operator[](size_t index) const {
    return data[index];
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    MyString res(lhs.length()+rhs.length());
    res += lhs;
    res += rhs;
    return res;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buff[1024];
    is >> buff;
    size_t buffLen = strlen(buff);

    if (buffLen > str.allocatedDataCapacity) {
        str.resize(buffLen);
    }
    strcpy(str.data, buff);
    str.currentSize = buffLen;

    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    return os << str.c_str();
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return !(lhs < rhs || lhs == rhs);
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs < rhs);
}

void swap(MyString& lhs, MyString& rhs) noexcept {
    MyString temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}