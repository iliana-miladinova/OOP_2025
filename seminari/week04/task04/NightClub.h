#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "Baloon.h"
#include "Narga.h"
#include "Alchohol.h"

namespace Constraints {
	constexpr size_t MAX_BALOONS = 1024;
	constexpr size_t MAX_ALCHOHOL = 512;
	constexpr size_t MAX_NARGAS = 256;
};


class NightClub {
private:
	Baloon baloons[Constraints::MAX_BALOONS];
	Narga nargas[Constraints::MAX_NARGAS];
	Alchohol alchohols[Constraints::MAX_ALCHOHOL];

	size_t baloonCount = 0;
	size_t nargaCount = 0;
	size_t alchoholCount = 0;

public:
	void addBaloon(const char* filename);
	void addNarga(const char* filename);
	void addAlchohol(const char* filename);
	void removeBaloonByColour(const char* colour);
	void removeNargaByTasteBrand(const char* brand, const char* taste);
	void removeAlchoholByBrand(const char* brand);
};