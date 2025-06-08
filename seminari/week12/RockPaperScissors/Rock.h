#pragma once
#include "Player.h"

class Rock :public Player {
public:
	explicit Rock(bool val);

	int playAgainst(const Player* other) const override;
	int playAgainstRock(const Rock* rock) const override;
	int playAgainstScissors(const Scissors* scissors) const override;
	int playAgainstPaper(const Paper* paper) const override;

	Player* clone() const override;
private:
	bool val;
};