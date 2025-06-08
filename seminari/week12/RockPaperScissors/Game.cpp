#include "Game.h"

Game::Game(size_t playersCount) :playersCount(playersCount) {
	players = new Player * [playersCount];
}

void Game::copyFrom(const Game& other) {
	players = new Player * [other.cap];
	for (size_t i = 0; i < other.cap; i++)
	{
		players[i] = other.players[i]->clone();
	}
	playersCount = other.playersCount;
	cap = other.cap;
}

void Game::moveFrom(Game&& other) noexcept {
	players = other.players;
	other.players = nullptr;
	playersCount = other.playersCount;
	cap = other.cap;
	other.playersCount = other.cap = 0;
}

void Game::free() {
	for (size_t i = 0; i < playersCount; i++)
	{
		delete[] players[i];
	}
	delete[] players;
	players = nullptr;
	playersCount = cap = 0;
}

void Game::resize(size_t newCap) {
	Player** resized = new Player * [newCap];
	for (size_t i = 0; i < playersCount; i++)
	{
		resized[i] = players[i];
	}
	delete[] players;
	players = resized;
	cap = newCap;
}

Game::Game(const Game& other) {
	copyFrom(other);
}

Game& Game::operator=(const Game& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Game::Game(Game&& other) noexcept {
	moveFrom(std::move(other));
}

Game& Game::operator=(Game&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Game::~Game() {
	free();
}

void Game::addPlayer(Player* player) {
	if (!player) {
		throw std::invalid_argument("Nullptr");
	}
	if (playersCount >= cap) {
		resize(cap * 2);
	}
	players[playersCount++] = player;
}

size_t Game::getPlayersCount() const {
	return playersCount;
}

bool Game::isValidInd(size_t ind) const {
	return ind < playersCount;
}

int Game::simulateDuel(size_t firstPlayerInd, size_t secondPlayerInd) const {
	if (!isValidInd(firstPlayerInd) || !isValidInd(secondPlayerInd)) {
		throw std::invalid_argument("Invalid ind of player");
	}
	if (firstPlayerInd == secondPlayerInd) {
		return 0;
	}

	return players[firstPlayerInd]->playAgainst(players[secondPlayerInd]);
}

size_t Game::simulateTournament() const {
	int maxRes = INT_MIN;
	size_t winnerInd = 0;
	for (size_t i = 0; i < playersCount; i++)
	{
		int currRes = 0;
		for (size_t j = 0; j < playersCount; j++)
		{
			currRes += simulateDuel(i, j);
		}

		if (currRes > maxRes) {
			winnerInd = i;
			maxRes = currRes;
		}
	}
	return winnerInd;
}