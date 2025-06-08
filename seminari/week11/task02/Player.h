#pragma once
#include <iostream>
#pragma warning(disable:4996)

enum class Stars {
	ONE=1,
	TWO,
	THREE,
	FOUR,
	FIVE
};

class Player {
protected:
	int id;
	int points;
	Stars star;
	static int idCounter;

	bool levelUpHelper(int twoStarsPoints, int threeStarsPoints, int fourStarsPoints, int fiveStarsPoints);

public:
	Player();
	Player(int id);
	virtual ~Player() = default;

	void addPoint(int newPoints);
	virtual bool levelUp();

};