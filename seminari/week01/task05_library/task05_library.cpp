// task05_library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum class Genre {
    Novel,
    Historical,
    Poetry,
    Other
};

struct Book {
    char title[50] = "";
    char author[50] = "";
    Genre genre = Genre::Other;
    bool isAvailable = true;
};

struct Library {
    unsigned numBooks = 0;
    Book books[5];
};

Genre initGenre(int genreNum) {
    switch (genreNum)
    {
    case 0: return Genre::Novel;
    case 1: return Genre::Historical;
    case 2: return Genre::Poetry;
    default:
        return Genre::Other;
    }
}

void initBook(Book& book) {
    int genreNum;
    std::cin >> book.title >> book.author >> genreNum >> book.isAvailable;
    book.genre = initGenre(genreNum);
}

void addBookToTheLibrary(Library& lib, const Book& book) {
    if (lib.numBooks == 5) {
        std::cout << "No more capacity"<<std::endl;
        return;
    }
    lib.books[lib.numBooks] = book;
    lib.numBooks++;
}

const Book& getBookByTitle(const char* title, Library& lib)  {
    for (int i = 0; i < lib.numBooks; i++) {
        if (strcmp(title, lib.books[i].title) == 0) {
            lib.books[i].isAvailable = false;
            return lib.books[i];
        }
    }
    std::cout << "Error" << std::endl;
}

void returnBookByTitle(const char* title, Library& lib) {
    for (int i = 0; i < lib.numBooks; i++) {
        if (strcmp(title, lib.books[i].title) == 0) {
            lib.books[i].isAvailable = true;
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }
   
}

const char* getStringFromGenre(const Genre& genre) {
    switch (genre)
    {
    case Genre::Novel: return "Novel";
    case Genre::Historical: return "Historical";
    case Genre::Poetry: return "Poetry";
    case Genre::Other: return "Other";
    }
}

void printInfoBook(const Book& book) {
    std::cout << book.title << ' ' << book.author << ' ' << getStringFromGenre(book.genre) << ' ' << book.isAvailable << std::endl;
}

void printInfoLib(const Library& lib) {
    for (int i = 0; i < lib.numBooks; i++) {
        printInfoBook(lib.books[i]);
    }
}

int main()
{
    Library lib;

    Book book;
    initBook(book);
    printInfoBook(book);
    addBookToTheLibrary(lib, book);
    printInfoLib(lib);
    int n;
    std::cin >> n;
    char* title = new char[n];
    std::cin >> title;
    Book b1 = getBookByTitle(title, lib);
    printInfoBook(b1);
    printInfoLib(lib);
    returnBookByTitle(title, lib);
    printInfoLib(lib);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
