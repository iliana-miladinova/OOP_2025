#pragma once
#include "Player.h"

constexpr size_t MAX_PASS = 8;
class LoggedPlayer : public Player {
private:
	char password[MAX_PASS + 1];
public:
	LoggedPlayer(const char* password);
	bool logIn(const char* password, int playerId);
};