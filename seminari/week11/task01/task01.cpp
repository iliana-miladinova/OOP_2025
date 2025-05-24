// task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "FileFactory.h"
#include "MyString.h"

void transfer(const MyString& fromRead, const MyString& toSave) {
	FileReader* reader = FileFactory::fileReaderFactory(fromRead);
	FileWriter* writer = FileFactory::fileWriterFactory(toSave);

	int* arr = nullptr;
	size_t size = 0;

	reader->read(arr, size);
	writer->write(arr, size);

	delete[] arr;
	delete reader;
	delete writer;
}

void createTestFiles() {
    std::ofstream textOut("data.arr");
    textOut << "1 2 3 4 5";
    textOut.close();
}

int main()
{
    createTestFiles();

    MyString from1("data.arr");
    MyString to1("copy1.dat");
    transfer(from1, to1); 

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
