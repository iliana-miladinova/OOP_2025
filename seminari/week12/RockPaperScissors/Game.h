#pragma once
#include "Player.h"

class Game {
public:
	explicit Game(size_t playersCount);

	Game(const Game& other);
	Game& operator=(const Game& other);

	Game(Game&& other) noexcept;
	Game& operator=(Game&& other) noexcept;

	~Game();

	void addPlayer(Player* player);

	size_t getPlayersCount() const;
	size_t simulateTournament() const;
private:
	Player** players = nullptr;
	size_t playersCount = 0;
	size_t cap = 0;

	void copyFrom(const Game& other);
	void moveFrom(Game&& other) noexcept;
	void free();
	void resize(size_t newCap);

	bool isValidInd(size_t ind) const;
	int simulateDuel(size_t firstPlayerInd, size_t secondPlayerInd) const;
};