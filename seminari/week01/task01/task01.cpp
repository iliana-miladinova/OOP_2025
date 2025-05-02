// task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Vector {
    int vector[3];
};

Vector sumVectors(const Vector& lhs, const Vector& rhs) {
    Vector res;
    for (int i = 0; i < 3; i++) {
        res.vector[i] = lhs.vector[i] + rhs.vector[i];
    }
    return res;
}

void printVectorCoordinates(const Vector& v) {
    for (int i = 0; i < 3; i++) {
        std::cout << v.vector[i] << ' ';
    }
    std::cout << std::endl;
}

bool areLNZ(const Vector& v1, const Vector& v2) {
    if (v1.vector[0] == 0 && v1.vector[1] == 0 && v1.vector[2] == 0) {
        return v2.vector[0] == 0 && v2.vector[1] == 0 && v2.vector[2] == 0;
    }
    else if (v2.vector[0] == 0 && v2.vector[1] == 0 && v2.vector[2] == 0) {
        return false;
    }

    if (v1.vector[0] * v2.vector[1] == v1.vector[1] * v2.vector[0]) {
        if (v1.vector[0] * v2.vector[2] == v1.vector[2] * v2.vector[0]) {
            if (v1.vector[1] * v2.vector[2] == v1.vector[2] * v2.vector[1]) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Vector v1 = { {1, 2, 3} };
    Vector v2 = { {2, 4, 6} };
    Vector sum = sumVectors(v1, v2);
    printVectorCoordinates(sum);
    std::cout << areLNZ(v1, v2) << std::endl;
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
