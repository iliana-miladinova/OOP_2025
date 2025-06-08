// task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Guest.h"
#include "LoggedPlayer.h"
#include "PremiumPlayer.h"

int main()
{
    std::cout << "=== Демонстрация на игрова система ===" << "\n\n";

    // 1. Тест на базовия клас Player
    std::cout << "----- Базов играч -----\n";
    Player basicPlayer;
    basicPlayer.addPoint(300);
   

    // 2. Тест на гост потребител
    std::cout << "----- Гост потребител -----\n";
    Guest guestPlayer(60); // 60 минути игра

    if (!guestPlayer.levelUp()) {
        std::cout << "Гостите не могат да наддават!\n\n";
    }

    // 3. Тест на логнат потребител
    std::cout << "----- Логнат потребител -----\n";
    LoggedPlayer loggedPlayer("secret12");
    if (loggedPlayer.levelUp()) {
        std::cout << "Логнатият потребител наддаде успешно!\n\n";
    }

    // 4. Тест на премиум потребител
    std::cout << "----- Премиум потребител -----\n";
    PremiumPlayer premiumPlayer("Иван Петров");
    

    Player* players[3];
    players[0] = new Guest(30);
    players[1] = new LoggedPlayer("mypass123");
    players[2] = new PremiumPlayer("Мария Иванова");

    for (int i = 0; i < 3; i++) {
        
        if (players[i]->levelUp()) {
            std::cout << "Успешно!";
        }
        else {
            std::cout << "Неуспешно!";
        }
        std::cout << "\n";
        delete players[i];
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
