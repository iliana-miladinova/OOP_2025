#include "Paper.h"
#pragma warning(disable:4996)

static bool isLowerCase(char ch) {
	return ch >= 'a' && ch <= 'z';
}

static bool isValidMessage(const char* message) {
	size_t len = strlen(message);
	for (size_t i = 0; i < len; i++)
	{
		if (!isLowerCase(message[i])) {
			return false;
		}
	}
	return true;
}

Paper::Paper(const char* message) {
	if (!message || !isValidMessage(message)) {
		throw std::invalid_argument("Invalid message");
	}

	this->message = new char[strlen(message) + 1];
	strcpy(this->message, message);
}

void Paper::copyFrom(const Paper& other) {
	message = new char[strlen(other.message) + 1];
	strcpy(this->message, other.message);
}

void Paper::moveFrom(Paper&& other) noexcept {
	message = other.message;
	other.message = nullptr;
}

void Paper::free() {
	delete[] message;
	message = nullptr;
}

Player* Paper::clone() const {
	return new Paper(*this);
}

Paper::Paper(const Paper& other) {
	copyFrom(other);
}

Paper& Paper::operator=(const Paper& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Paper::Paper(Paper&& other) noexcept {
	moveFrom(std::move(other));
}

Paper& Paper::operator=(Paper&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Paper::~Paper() {
	free();
}

int Paper::playAgainst(const Player* other) const {
	return -(other->playAgainstPaper(this)); //asks other whats the score against this(paper) and returns the score with - to get the score for the current object(this(paper))
}

int Paper::playAgainstPaper(const Paper* paper) const {
	return strcmp(this->message, paper->message);
}

int Paper::playAgainstRock(const Rock* rock) const {
	return 1;
}

int Paper::playAgainstScissors(const Scissors* scissors) const {
	return -1;
}