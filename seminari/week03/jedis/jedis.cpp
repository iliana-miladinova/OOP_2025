// jedis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

namespace Constraints {
    constexpr size_t NAME_LEN = 50;
    constexpr size_t MAX_JEDIS = 100;
}

enum class Colour {
    RED, 
    YELLOW, 
    GREEN, 
    BLUE, 
    PURPLE
};

enum class Type {
    SINGLEBLADED, 
    DOUBLE_BLADED, 
    CROSSGUARD
};

struct LightSaber {
    Colour colour;
    Type type;
};

struct Jedi {
    char name[Constraints::NAME_LEN];
    unsigned age;
    unsigned power;
    LightSaber lightsaber;
};

struct JediCollection {
    Jedi jedies[Constraints::MAX_JEDIS];
    unsigned count = 0;
};

Jedi createJedi(const char* name, unsigned age, unsigned power, const LightSaber& lightsaber) {
    Jedi j;
    strcpy(j.name, name);
    j.age = age;
    j.power = power;
    j.lightsaber = lightsaber;

    return j;
}

Jedi createJedi(const char* name, unsigned age, unsigned power, const Colour& c, const Type& type) {
    LightSaber ls;
    ls.colour = c;
    ls.type = type;
    return createJedi(name, age, power, ls);
}

void addJedi(JediCollection& collection, const Jedi& jedi) {
    if (collection.count == Constraints::MAX_JEDIS) {
        std::cout << "Cannot add more jedies" << std::endl;
        return;
    }
    collection.jedies[collection.count] = jedi;
    collection.count++;
}

int findIndByName(const JediCollection& collection, const char* name) {
    for (size_t i = 0; i < collection.count; i++) {
        if (strcmp(collection.jedies[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void removeJedi(JediCollection& collection, const char* name) {
    int ind = findIndByName(collection, name);
    if (ind == -1) {
        std::cout << "No such jedi" << std::endl;
        return;
    }

    for (size_t i = ind + 1; i < collection.count; i++) {
        collection.jedies[i - 1] = collection.jedies[i];
    }
    collection.count--;
}

const char* getTextFromColour(const Colour& c) {
    switch (c)
    {
    case Colour::RED: return "Red";
    case Colour::YELLOW: return "Yellow";
    case Colour::GREEN: return "Green";
    case Colour::BLUE: return "Blue";
    case Colour::PURPLE: return "Purple";
    default: return "Unknown";
    }
}

const char* getTextFromType(const Type& type) {
    switch (type)
    {
    case Type::SINGLEBLADED: return "Singlebladed";
    case Type::DOUBLE_BLADED: return "Doublebladed";
    case Type::CROSSGUARD: return "Crossguard";
    default: return "Unknown";
    }
}

void printJedi(const Jedi& jedi) {
    std::cout << jedi.name << " " << jedi.age << " " << jedi.power << " " << 
        getTextFromColour(jedi.lightsaber.colour) << " " << 
        getTextFromType(jedi.lightsaber.type) << std::endl;
}

void printJediCollection(const JediCollection& collection) {
    for (size_t i = 0; i < collection.count; i++) {
        printJedi(collection.jedies[i]);
    }
}

void saveCollectionToBinary(const char* fileName, const JediCollection& collection) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    file.write((const char*)&collection, sizeof(collection));
}

JediCollection readCollectionFromBinary(const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return {};
    }
    JediCollection collection;
    file.read((char*)&collection, sizeof(collection));
    return collection;
}

void saveJediToTxt(std::ofstream& file, const Jedi& j) {
    file << j.name << ' ' << j.age << ' ' << j.power << ' ' << int(j.lightsaber.type) << ' ' << int(j.lightsaber.colour) << std::endl;
}

void saveCollectionToTxt(const char* fileName, const JediCollection& collection) {
    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }
    ofs << collection.count << std::endl;
    for (size_t i = 0; i < collection.count; i++)
    {
        saveJediToTxt(ofs, collection.jedies[i]);
    }
}

void readJediFromTxt(std::ifstream& ifs, Jedi& j) {
    ifs.getline(j.name, 1024, ' ');
    ifs >> j.age;
    ifs.ignore();
    ifs >> j.power;
    ifs.ignore();

    int colour, type;
    ifs >> type;
    j.lightsaber.type = Type(type);
    ifs.ignore();
    ifs >> colour;
    j.lightsaber.colour = Colour(colour);
    
    
}
JediCollection readCollectionToTxt(const char* fileName) {
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return {};
    }

    JediCollection collection;
    ifs >> collection.count;
    ifs.ignore();
    for (size_t i = 0; i < collection.count; i++)
    {
        readJediFromTxt(ifs, collection.jedies[i]);
        ifs.ignore();
    }
    return collection;
}

bool sortByPower(const Jedi& lhs, const Jedi& rhs) {
    return lhs.power < rhs.power;
}

bool SortByAge(const Jedi& lhs, const Jedi& rhs) {
    return lhs.age < rhs.age;
}
void sortBy(JediCollection& collection, bool(*pred)(const Jedi& lhs, const Jedi& rhs)) {
    for (size_t i = 0; i < collection.count; i++)
    {
        int minInd = i;
        for (size_t j = i+1; j < collection.count; j++)
        {
            if (pred(collection.jedies[j], collection.jedies[minInd])) {
                minInd = j;
            }
        }
        if (minInd!=i)
        {
            std::swap(collection.jedies[i], collection.jedies[minInd]);
        }
    }
}
int main()
{
    /*LightSaber lb;
    lb.colour = Colour::GREEN;
    lb.type = Type::DOUBLE_BLADED;
    Jedi j = createJedi("Ivan", 14, 1400, lb);
    Jedi j2 = createJedi("Georgi", 17, 140, Colour::BLUE, Type::SINGLEBLADED);
    JediCollection collection;
    addJedi(collection, j);
    addJedi(collection, j2);
    printJediCollection(collection);
    saveCollectionToBinary("jedi.dat", collection);
    saveCollectionToTxt("jedi.txt", collection);*/

    JediCollection collection = readCollectionFromBinary("jedi.dat");
    JediCollection collection2 = readCollectionToTxt("jedi.txt");
    printJediCollection(collection);
    std::cout << "---------------------------------------" << std::endl;
    printJediCollection(collection2);

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
