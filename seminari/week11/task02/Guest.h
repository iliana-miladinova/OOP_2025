#pragma once
#include "Player.h"

class Guest : public Player {
private:
	unsigned time;

public:
	Guest(unsigned time);
	bool levelUp() override;
};