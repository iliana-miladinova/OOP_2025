// task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Peak.h"
#include "TPeak.h"
#include "MPeak.h"

int main()
{
    Peak* p1 = new TPeak(2925, "Rila", "Musala");
    Peak* p2 = new TPeak(2376, "Rila", "Maliovitsa");
    Peak* p3 = new MPeak(1241, "Stara Planina", 54291);
    Peak* p4 = new MPeak(1443, "Pirin", 33077);

    Peak* peaks[] = { p1, p2, p3, p4};

    for (Peak* peak : peaks) {
        std::cout << peak->getMountainName() << " - ";
        peak->printPeakName();
    }

    for (Peak* peak : peaks) {
        delete peak;
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
