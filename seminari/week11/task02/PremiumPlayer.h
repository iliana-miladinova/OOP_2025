#pragma once
#include "Player.h"

class PremiumPlayer :public Player {
private:
	char* name;

	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other);
	void free();
public:
	PremiumPlayer(const char* _name);
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other) noexcept;
	PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;

	bool levelUp() override;

	~PremiumPlayer();
};