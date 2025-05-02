#include "Book.h"

Book::Book(const char* title, int pagesCount) : pagesCount(pagesCount) {
	strcpy(this->title, title);
}

const char* Book::getTitle() const {
	return title;
}

void Book::printBook() const {
	std::cout << this->title << " " << this->pagesCount << std::endl;
}