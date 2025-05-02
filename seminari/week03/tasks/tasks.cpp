// tasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

int getFileSize(std::ifstream& file) {
    int curr = file.tellg();
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.seekg(curr);
    return size;
}

//task02
struct Student {
    char name[50];
    int age;
    int fn;
};

void initStudent(Student& s, const char* name, int age, int fn) {
    strcpy(s.name, name);
    s.age = age;
    s.fn = fn;
}

void saveToFile(const Student* students, size_t count, std::ofstream& file) {
    file.write((const char*)students, count * sizeof(Student));
}

void readFromFile(Student*& students, size_t& count, std::ifstream& file) {
    int fileSize = getFileSize(file);
    count = fileSize / sizeof(Student);
    students = new Student[count];
    file.read((char*)students, fileSize);
}

//task03
void findMissingBytes(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    bool foundBytes[256];
    char byte;
    while (ifs.read((char*)&byte, sizeof(byte))) {
        foundBytes[byte] = true;
    }

    for (size_t i = 0; i < 256; i++)
    {
        if (!foundBytes[i]) {
            std::cout << i << std::endl;
        }
    }
}

int main()
{
    //task01
    /*std::ofstream file("test.txt", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
    }

    char testData[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    file.write((const char*)testData, sizeof(testData));
    file.close();

    std::ifstream file1("test.txt", std::ios::binary);
    if (!file1.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
    }

    int size = getFileSize(file1);
    file1.close();
    std::cout << size << std::endl;*/

    //task02

   /* Student* arr = new Student[3];
    initStudent(arr[0], "Iliana", 20, 123);
    initStudent(arr[1], "Raya", 20, 234);
    initStudent(arr[2], "Maria", 25, 345);

    std::ofstream file("students.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error while opening the file!" << std::endl;
        delete[] arr;
        return -1;

    }
    saveToFile(arr, 4, file);
    delete[] arr;*/

    Student* arr;
    size_t count;
    std::ifstream file("students.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error while opening the file!" << std::endl;
        return -1;

    }

    readFromFile(arr, count, file);
    for (int i = 0; i < count-1; i++) {
        std::cout << arr[i].name << " " << arr[i].age << " " << arr[i].fn << std::endl;
    }
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
