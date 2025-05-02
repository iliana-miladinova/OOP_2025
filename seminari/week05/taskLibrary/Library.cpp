#include "Library.h"

void Library::copyFrom(const Library& other) {
	books = new Book[other.size];
	for (int i = 0; i < size; i++) {
		books[i] = other.books[i];
	}
	capacity = other.capacity;
	size = other.size;
}

void Library::free() {
	delete[] books;
	size = capacity = 0;
}

void Library::resize(int newCap) {
	Book* temp = new Book[newCap];
	for (int i = 0; i < size; i++) {
		temp[i] = books[i];
	}

	delete[] books;
	books = temp;
	capacity = newCap;
}

Library::Library() {
	size = 0;
	capacity = 3;
	books = new Book[capacity];
}

Library::Library(const Library& other) {
	copyFrom(other);
}

Library& Library::operator=(const Library& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Library::~Library() {
	free();
}

void Library::addBook(const Book& book) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	books[size] = book;
	size++;
}

void Library::addBook(const char* title, int pagesCount) {
	if (!title) {
		return;
	}

	Book book(title, pagesCount);
	addBook(book);

}

void Library::removeBookByInd(int ind) {
	if (ind == 0 || ind >= size) {
		throw std::out_of_range("Invalid ind");
	}

	for (int i = ind; i < size - 1; i++) {
		books[i] = books[i + 1];
	}
	size--;
}

int Library::getInd(const char* title) const {
	if (!title || size == 0) {
		throw std::exception("Error");
	}

	int ind = -1;
	for (int i = 0; i < size; i++) {
		if (strcmp(title, books[i].getTitle()) == 0) {
			ind=i;		
		}
	}
	return ind;
}

void Library::removeBookByTitle(const char* title) {
	if (size == 0 || !title) {
		throw std::exception("Error");
	}
	int ind = getInd(title);

	if (ind == -1) {
		throw std::exception("No such title");
	}

	removeBookByInd(ind);
}

void Library::printLibrary() const {
	for (int i = 0; i < size; i++) {
		books[i].printBook();
	}
}