// task08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

constexpr size_t BUFF_SIZE = 1024;

char* getKeyFromLineInFile(const char* line) {
    char* key = new char[BUFF_SIZE];
    int keyInd = 0;
    int lineInd = 0;
    while (line[lineInd]!='\0') {
        if (line[lineInd] == ' ') {
            break;
        }
        else {
            key[keyInd++] = line[lineInd];
        }
        lineInd++;
    }
    key[keyInd] = '\0';

    return key;
}

int getStartForValueWord(const char* line) {
    int lineInd = 0;
    while (line[lineInd] != '\0' && line[lineInd] != ' ') {
        lineInd++;
    }

    while (line[lineInd] == ' ') {
        lineInd++;
    }
    return lineInd;
}

char* getValueFromLine(const char* line) {
    int startPos = getStartForValueWord(line);
    char* value = new char[BUFF_SIZE];
    int valInd = 0;
    while (line[startPos] != '\0') {
        if (line[startPos] == '\n') {
            break;
        }
        else {
            value[valInd++] = line[startPos];
        }
        startPos++;
    }
    value[valInd] = '\0';
    return value;
}

char* readValueFromFileWithKeysAndValues(const char* filename, const char* tag) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return nullptr;
    }

    char buff[BUFF_SIZE];
    while (ifs.getline(buff, BUFF_SIZE)) {
        char* key = getKeyFromLineInFile(buff);
        if (strcmp(key, tag) == 0) {
            delete[] key;
            char* val = getValueFromLine(buff);
            return val;
        }
    }
    return nullptr;
}

char* getTagFromTemplate(std::ifstream& ifs) {
    char* tag = new char[BUFF_SIZE];
    char ch;
    int ind = 0;
    while (ifs.get(ch)) {
        if (ch == '}') {
            break;
        }
        else {
            tag[ind++] = ch;
        }
    }
    tag[ind] = '\0';
    
    return tag;

}

void replaceInTemplate(const char* templatename, const char* valueFile, const char* newFile) {
    std::ifstream ifs(templatename);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    std::ofstream ofs(newFile);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    char ch;
    while (ifs.get(ch)) {
        if (ifs.eof()) {
            break;
        }
        if (ch == '{') {
            char* tag = getTagFromTemplate(ifs);
            char* val = readValueFromFileWithKeysAndValues(valueFile, tag);
            ofs << val;
            continue;
        }
        ofs << ch;
    }
}


int main()
{
    replaceInTemplate("template.txt", "values.txt", "newFile.txt");
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
