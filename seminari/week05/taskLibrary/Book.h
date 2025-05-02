#pragma once
#pragma warning (disable:4996)
#include <iostream>

constexpr size_t MAX_LEN = 256;
class Book {
private:
	char title[MAX_LEN];
	int pagesCount = 0;

public:
	Book() = default;
	Book(const char* title, int pagesCount);
	const char* getTitle() const;

	void printBook() const;
};