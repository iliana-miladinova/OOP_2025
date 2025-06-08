#pragma once
#include "Player.h"

class Paper : public Player {
public:
	explicit Paper(const char* message);

	Paper(const Paper& other);
	Paper& operator=(const Paper& other);

	Paper(Paper&& other) noexcept;
	Paper& operator=(Paper&& other) noexcept;
	
	~Paper();

	int playAgainst(const Player* other) const override;
	int playAgainstPaper(const Paper* paper) const override;
	int playAgainstScissors(const Scissors* scissors) const override;
	int playAgainstRock(const Rock* rock) const override;

	Player* clone() const override;
private:
	char* message = nullptr;

	void copyFrom(const Paper& other);
	void moveFrom(Paper&& other) noexcept;
	void free();
};