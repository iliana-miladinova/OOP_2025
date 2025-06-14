// Restaurant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Restaurant.h"
#include "Food.h"
#include "Drink.h"
#include <iostream>

int main() {
    Restaurant restaurant;

    Food pizza(10, 8.50, "Pizza", 0.400);     // 10 бр, 8.50 лв, 400гр
    Food salad(5, 4.20, "Salad", 0.250);      // 5 бр, 4.20 лв, 250гр

    Drink water(20, 1.80, "Mineral Water", 0.0); // 20 бр, безалкохолна
    Drink wine(15, 9.00, "Red Wine", 12.5);      // 15 бр, алкохолна

    // Добавяне към ресторанта
    restaurant.addProduct(pizza);
    restaurant.addProduct(salad);
    restaurant.addProduct(water);
    restaurant.addProduct(wine);

    std::cout << "\n=== ALL PRODUCTS ===\n";
    restaurant.printAll();

    std::cout << "\n=== NON-ALCOHOLIC DRINKS ===\n";
    restaurant.printNonAlchoholicDrinks();

    return 0;
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
