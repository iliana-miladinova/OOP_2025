#include "RPSPlayerFactory.h"

Paper* RPSPlayerFactory::createPaper(std::istream& is) {
	char message[1024];
	is >> message;
	return new Paper(message);
}

Rock* RPSPlayerFactory::createRock(std::istream& is) {
	bool val;
	is >> val;
	return new Rock(val);
}

Scissors* RPSPlayerFactory::createScissors(std::istream& is) {
	int val;
	is >> val;
	return new Scissors(val);
}

Player* RPSPlayerFactory::createPlayer(std::istream& is) {
	int playerType;
	is >> playerType;

	switch (playerType)
	{
	case 0: return createRock(is);
	case 1: return createPaper(is);
	case 2: return createScissors(is);
	}
	throw std::invalid_argument("Invalid player type");
}