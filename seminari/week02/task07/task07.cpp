// task07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

namespace Constraints {
    constexpr size_t NAME_LEN = 63;
    constexpr size_t MAX_CITIES = 20;
}

struct City {
    char name[Constraints::NAME_LEN] = {};
    unsigned citizens = 0;
};

struct Distinct {
    City cities[Constraints::MAX_CITIES] = {};
    int citiesCount = 0;

    void addCity(const City& c) {
        if (citiesCount < Constraints::MAX_CITIES) {
            cities[citiesCount++] = c;
        }
        else {
            std::cout << "Error" << std::endl;
            return;
        }
    }
};

void writeCityToFile(std::ofstream& ofs, const City& c) {
    ofs << c.name << ' ' << c.citizens << std::endl;
}

void writeDistinctToFile(const char* fileName, const Distinct& d) {
    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
    }

    ofs << d.citiesCount << std::endl;
    for (int i = 0; i < d.citiesCount; i++) {
        writeCityToFile(ofs, d.cities[i]);
    }
    ofs.close();

}

void readCityFromFile(std::ifstream& ifs, City& c) {
    ifs >> c.name >> c.citizens;
}

void readDistinctFromFile(const char* fileName, Distinct& d) {
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
    }

    ifs >> d.citiesCount;
    for (size_t i = 0; i < d.citiesCount; i++)
    {
        readCityFromFile(ifs, d.cities[i]);
    }

    ifs.close();
}

void sortCitiesInDistinct(City* cities, size_t size) {
    for (size_t i = 0; i < size-1; i++)
    {
        int minInd = i;
        for (size_t j = i; j < size; j++)
        {
            if (cities[j].citizens < cities[minInd].citizens) {
                minInd = j;
            }
        }
        if (minInd != i) {
            std::swap(cities[i], cities[minInd]);
        }
    }
}

void sortDistinct(const char* inputFileName, const char* outputFileName, Distinct& d) {
    readDistinctFromFile(inputFileName, d);
    sortCitiesInDistinct(d.cities, d.citiesCount);
    writeDistinctToFile(outputFileName, d);
}

int main()
{
    City c1{ "Iliana", 20 };
    City c2{ "Blg", 50 };
    City c3{ "Sofia", 30 };
    Distinct d;
    d.addCity(c1);
    d.addCity(c2);
    d.addCity(c3);

    writeDistinctToFile("distincts.txt", d);
    sortDistinct("distincts.txt", "sorted.txt", d);
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
