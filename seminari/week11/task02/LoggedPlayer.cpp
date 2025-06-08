#include "LoggedPlayer.h"

LoggedPlayer::LoggedPlayer(const char* password):Player() {
	if (strlen(password) > 8) {
		throw std::length_error("Too long password");
	}
	strcpy(this->password, password);
}

bool LoggedPlayer::logIn(const char* password, int playerId) {
	if (strcmp(this->password, password) == 0 && playerId == id) {
		return true;
	}
	return false;
}