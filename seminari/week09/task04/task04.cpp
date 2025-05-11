// task04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foodpanda.h"
#include "Order.h"

int main() {
    try {
        Foodpanda fp(2);

        Restaurant r1("Happy", 2);
        r1.addProduct(MyString("Pizza"));
        r1.addProduct(MyString("Pasta"));

        fp.addRestaurant(r1);

        fp.addProductToRest(MyString("Salad"), r1);

        Order o1("Happy");
        o1.addProduct(MyString("Pizza"));
        o1.addProduct(MyString("Salad"));

        fp.addOrderToRest(o1);

        std::cout << "Order for restaurant " << o1.getRestaurantName() << " accepted. Delivery time: " << o1.getDeliveryTime() << " minutes.\n";
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid argument: " << ex.what() << '\n';
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << '\n';
    }

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
