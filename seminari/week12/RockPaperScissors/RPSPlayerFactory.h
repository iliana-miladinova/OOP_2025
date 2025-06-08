#pragma once
#include "Player.h"
#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

class RPSPlayerFactory {
public:
	RPSPlayerFactory() = delete;//we forbid the creation of objects from this class

	static Player* createPlayer(std::istream& is); //static, so we can call the function without an object
	static Rock* createRock(std::istream& is);
	static Paper* createPaper(std::istream& is);
	static Scissors* createScissors(std::istream& is);
};