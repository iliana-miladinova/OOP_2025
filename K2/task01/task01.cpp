// task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector2D.h"

int main()
{
    Vector2D a(3.0, 4.0);
    Vector2D b(1.0, 2.0);

    Vector2D c = a + b;
    std::cout << "a + b = (" << c.getX() << ", " << c.getY() << ")" << std::endl;

    Vector2D d = a * 2.0;
    Vector2D e = 2.0 * b;
    std::cout << "a * 2 = (" << d.getX() << ", " << d.getY() << ")" << std::endl;
    std::cout << "2 * b = (" << e.getX() << ", " << e.getY() << ")" << std::endl;

    double dot = a ^ b;
    std::cout << "a ^ b = " << dot << std::endl;

    a += b;
    std::cout << "a += b => a = (" << a.getX() << ", " << a.getY() << ")" << std::endl;

    std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
    std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;

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
