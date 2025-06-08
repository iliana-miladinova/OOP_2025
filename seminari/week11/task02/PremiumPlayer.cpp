#include "PremiumPlayer.h"

void PremiumPlayer::copyFrom(const PremiumPlayer& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other) {
	name = other.name;
	other.name = nullptr;
}

void PremiumPlayer::free() {
	delete[] name;
}

PremiumPlayer::PremiumPlayer(const char* _name) : Player() {
	if (!_name && this->name == _name) {
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other):Player(other) {
	copyFrom(other);
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other) {
	if (this != &other) {
		Player::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other)noexcept :Player(std::move(other)) {
	moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept{
	if (this != &other) {
		Player::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

PremiumPlayer::~PremiumPlayer() {
	free();
}

bool PremiumPlayer::levelUp() {
	return levelUpHelper(256, 512, 768, 1024);
}