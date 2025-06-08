#include "Rock.h"

Rock::Rock(bool val) :val(val) {

}

int Rock::playAgainst(const Player* other) const {
	return -(other->playAgainstRock(this));
}

int Rock::playAgainstPaper(const Paper* paper) const {
	return -1;
}

int Rock::playAgainstScissors(const Scissors* scissors) const {
	return 1;
}

int Rock::playAgainstRock(const Rock* rock) const {
	if (val > rock->val) {
		return 1;
	}
	else if (val < rock->val) {
		return -1;
	}
	return 0;
}

Player* Rock::clone() const {
	return new Rock(*this);
}