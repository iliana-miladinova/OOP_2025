// task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 1024;

int task03(std::ifstream& f1, std::ifstream& f2) {
    int line = 1;
    while (!f1.eof() || !f2.eof()) {
        char buff1[BUFF_SIZE];
        char buff2[BUFF_SIZE];
        f1.getline(buff1, BUFF_SIZE);
        f2.getline(buff2, BUFF_SIZE);
        if (strcmp(buff1, buff2) == 0) {
            line++;
        }
        else {
            return line;
        }
    }
    if (!f1.eof() || !f2.eof()) {
        return line;
    }
    return 0;
}

void task04(std::ifstream& f1, std::ifstream& f2) {
    std::ofstream f3("concat.txt");
    if (!f3.is_open()) {
        "Cannot open file for writing";
        return;
    }
    char buff[BUFF_SIZE];
    /*while (!f1.eof()) {
        char buff[BUFF_SIZE];
        f1.getline(buff, BUFF_SIZE);

        f3 << buff;
        f3 << '\n';
    }*/
    while (f1.getline(buff, BUFF_SIZE)) {
        f3 << buff;
        f3 << '\n';
    }
    while (f2.getline(buff, BUFF_SIZE)) {
        f3 << buff;
        f3 << '\n';
    }

    
}

void task04WithoutInterval(std::ifstream& f1, std::ifstream& f2) {
    std::ofstream f3("concat.txt");
    if (!f3.is_open()) {
        std::cerr<<"Cannot open file for writing"<<std::endl;
        return;
    }
    char ch;
    while (f1.get(ch)) {
        if (ch == ' ') {
            ch = ',';
        }
        f3.put(ch);
    }
    /*f3 << '\n';*/
    while (f2.get(ch)) {
        if (ch == ' ') {
            ch = ',';

        }
        f3.put(ch);
    }
    f3.close();
}

void task05(const char* inputFileName, const char* outputFileName, const char* oldWord, const char* newWord) {
    std::ifstream ifs(inputFileName);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading";
        return;
    }

    std::ofstream ofs(outputFileName);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing";
        return;
    }

    char buff[BUFF_SIZE];
    bool firstWord = true;
    while (ifs>>buff) {
        if (!firstWord) {
            ofs << ' ';
        }
        firstWord = false;
        if (strcmp(buff, oldWord) == 0) {
            ofs << newWord;
        }
        else {
            ofs << buff;
        }

        if (ifs.peek() == '\n') {
            ofs << '\n';
            ifs.ignore();
            firstWord = true;
        }
    }
}
int main()
{
    //task 01
    /*std::ifstream file("digits.txt");
    if (!file.is_open()) {
        std::cout << "Cannot open file for reading";
    }
    int n1, n2;
    file >> n1 >> n2;
    std::cout << (n1 + n2) << std::endl;*/

    //task02
    /*std::ifstream file("maxNum.txt");
    if (!file.is_open()) {
        std::cout << "Cannot open file for reading";
    }
    size_t currPos = file.tellg();
    int num;
    int max = 0;
    while (!file.eof()) {
        file >> num;
        if (num > max) {
            max = num;
        }
    }
    file.seekg(currPos);
    std::cout << max << std::endl;*/

    //task03
    /*std::ifstream f1("file1.txt");
    std::ifstream f2("file2.txt");
    std::cout << task03(f1, f2) << std::endl;*/

    //task04
    /*std::ifstream file("maxNum.txt");
    if (!file.is_open()) {
        std::cout << "Cannot open file for reading1" << std::endl;
    }
    std::ifstream f1("file1.txt");
    if (!f1.is_open()) {
        std::cout << "Cannot open file for reading2" << std::endl;
    }
    task04WithoutInterval(file, f1);*/

    //task 05
    task05("oldFile.txt", "newFile.txt", "sun", "moon");
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
