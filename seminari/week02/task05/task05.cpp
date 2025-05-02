// task05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

void changeWord(const char* fileName, const char* newFileName, const char* word, const char* newWord) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Error" << std::endl;
        return;
    }

    std::ofstream outputFile(newFileName);
    if (!outputFile.is_open()) {
        std::cout << "Error" << std::endl;
        inputFile.close();
        return;
    }

    char buff[1024];
    while (inputFile.getline(buff, 1024)) {
        char newBuff[1024] = { 0 };
        char tempWord[20];
        int buffLen = std::strlen(buff);
        int newBuffInd = 0;

        for (int i = 0; i < buffLen;) {
            int j = 0;
            while (i < buffLen && (isAlpha(buff[i]) || isDigit(buff[i]))) {
                tempWord[j] = buff[i];
                i++;
                j++;
            }
            tempWord[j] = '\0';

            if (std::strlen(tempWord) > 0) {
                if (std::strcmp(tempWord, word) == 0) {
                    strcpy(&newBuff[newBuffInd], newWord);
                    newBuffInd += strlen(newWord);
                }
                else {
                    strcpy(&newBuff[newBuffInd], tempWord);
                    newBuffInd += strlen(tempWord);
                }
            }

            while (i < buffLen && !isAlpha(buff[i]) && !isDigit(buff[i])) {
                newBuff[newBuffInd] = buff[i];
                i++;
                newBuffInd++;
            }
        }
        newBuff[newBuffInd] = '\0';
        outputFile << newBuff << std::endl;
    }
    inputFile.close();
    outputFile.close();
}

int main()
{
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    const char* oldWord = "sun";
    const char* newWord = "moon";

    changeWord(inputFile, outputFile, oldWord, newWord);
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
