#pragma once
#include "Book.h"

class Library {
private:
	Book* books;
	int size;
	int capacity;

	void copyFrom(const Library& other);
	void free();
	void resize(int newCap);

	int getInd(const char* title) const;
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	void addBook(const Book& book);
	void addBook(const char* title, int pagesCount);

	void removeBookByInd(int ind);
	void removeBookByTitle(const char* title);

	void printLibrary() const;
};