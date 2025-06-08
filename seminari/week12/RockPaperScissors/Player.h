#pragma once
#include <iostream>

class Rock;
class Paper;
class Scissors;

class Player {
public:
	virtual int playAgainst(const Player* other) const = 0;
	virtual int playAgainstRock(const Rock* rock) const = 0;
	virtual int playAgainstScissors(const Scissors* scissors) const = 0;
	virtual int playAgainstPaper(const Paper* paper) const = 0;

	virtual Player* clone() const = 0;
	virtual ~Player() = default;
};