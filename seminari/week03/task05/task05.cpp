// task05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

constexpr size_t TITLE_LEN = 128;

struct Book
{
    char title[TITLE_LEN];
    int year;
    double price;
};

void readBook(std::ifstream& ifs, Book& book) {
    ifs.getline(book.title, TITLE_LEN, ' ');
    ifs >> book.year;
    //ifs.ignore();
    ifs >> book.price;
}

void resize(Book*& books, int& maxSize, int count) {
    maxSize *= 2;
    Book* temp = new Book[maxSize];
    for (int i = 0; i < count; i++) {
        temp[i] = books[i];
    }
    delete[] books;
    books = temp;
}

void readBookFile(const char* fileName, Book*& books, int& count) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    int maxSize = 50;
    books = new Book[maxSize];
    while (!ifs.eof()) {
        if (count >= maxSize) {
            resize(books, maxSize, count);
        }
        readBook(ifs, books[count]);
        
        count++;
        ifs.ignore();
        
    }

    ifs.close();
}

void readYearsAndSaveBooks(const char* filename, const Book* books, int bookCount, const char* booksFile) {
    std::ifstream ifs(filename, std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    std::ofstream ofs(booksFile, std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    int year;
    while (true) {
        ifs.read((char*)&year, sizeof(year));
        if (!ifs || ifs.eof()) {
            break;
        }
        for (size_t i = 0; i < bookCount; i++)
        {
            if (year == books[i].year) {
                ofs.write((const char*)&books[i], sizeof(Book));
            }
        }
    }

    ifs.close();
    ofs.close();
}

void createYearFile(const char* filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Cannot open file for writing" << std::endl;
        return;
    }

    int years[] = { 1997, 2021, 2005, 2010,2023 }; 
    int size = sizeof(years) / sizeof(years[0]);

    ofs.write((const char*)&years, size * sizeof(int));

    ofs.close();
}

void readBookFileBin(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::binary);  

    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    Book book;
    while (true) {
        ifs.read((char*)&book, sizeof(book));
        if (!ifs || ifs.eof()) {
            break;
        }
        std::cout << "Title: " << book.title
            << ", Year: " << book.year
            << ", Price: $" << book.price << std::endl;
    }

    ifs.close();
}

int main()
{
    Book* books = nullptr;
    int bookCount = 0;

    readBookFile("books.txt", books, bookCount);

    for (int i = 0; i < bookCount; i++) {
        std::cout << "Title: " << books[i].title
            << ", Year: " << books[i].year
            << ", Price: $" << books[i].price << std::endl;
    }
    //createYearFile("year.dat");

    readYearsAndSaveBooks("year.dat", books, bookCount, "book.dat");

    readBookFileBin("book.dat");
   
    delete[] books;
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
