#include "Scissors.h"

Scissors::Scissors(int val) :val(val) {

}

int Scissors::playAgainst(const Player* other) const{
	return -(other->playAgainstScissors(this));
}

int Scissors::playAgainstPaper(const Paper* paper) const {
	return 1;
}

int Scissors::playAgainstRock(const Rock* rock) const {
	return -1;
}

int Scissors::playAgainstScissors(const Scissors* scisssors) const {
	if (val > scisssors->val) {
		return 1;
	}
	else if (val < scisssors->val) {
		return -1;
	}
	return 0;
}

Player* Scissors::clone() const {
	return new Scissors(*this);
}