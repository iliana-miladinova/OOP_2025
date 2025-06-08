#include "Player.h"

int Player::idCounter = 0;

Player::Player() {
	idCounter++;
	id = idCounter;
	star = Stars::ONE;
	points = 0;
}

Player::Player(int id) :id(id), points(0), star(Stars::ONE) {

}

void Player::addPoint(int newPoints) {
	points += newPoints;
}

bool Player::levelUpHelper(int twoStarsPoints, int threeStarsPoints, int fourStarsPoints, int fiveStarsPoints) {
	switch (star) {
	case Stars::ONE:
		if (points >= twoStarsPoints && points < threeStarsPoints) {
			points -= twoStarsPoints;
			star = Stars::TWO;
			return true;
		}
		break;
	case Stars::TWO:
		if (points >= threeStarsPoints && points < fourStarsPoints) {
			points -= threeStarsPoints;
			star = Stars::THREE;
			return true;
		}
		break;
	case Stars::THREE:
		if (points >= fourStarsPoints && points < fiveStarsPoints) {
			points -= fourStarsPoints;
			star = Stars::FOUR;
			return true;
		}
		break;
	case Stars::FOUR:
		if (points >= fiveStarsPoints) {
			points -= fiveStarsPoints;
			star = Stars::FIVE;
			return true;
		}
		break;
	case Stars::FIVE:
		break;
	default:
		break;
	}
	return false;
}
bool Player::levelUp() {
	/*if (points >= 256 && points<512) {
		star = Stars::TWO;
		return true;
	}
	else if (points >= 512 && points < 1024 && star == Stars::TWO) {
		star = Stars::THREE;
		return true;
	}
	else if (points >= 1024 && points < 2048 && star == Stars::THREE) {
		star = Stars::FOUR;
		return true;
	}
	else if (points >= 2048 && star == Stars::FOUR) {
		star = Stars::FIVE;
		return true;
	}
	return false;*/
	return levelUpHelper(256, 512, 1024, 2048);
}