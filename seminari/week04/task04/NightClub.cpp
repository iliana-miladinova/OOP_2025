#include "NightClub.h"

void NightClub::addBaloon(const char* filename) {
	if (baloonCount >= Constraints::MAX_BALOONS) {
		throw std::runtime_error("Too much baloons!");
	}
	baloons[baloonCount].createBaloonFromFile(filename);
	size_t currCount = baloons[baloonCount].getCount();
	if (currCount == 0) {
		baloonCount++;
	}
	baloons[baloonCount].setCount(currCount + 1);
}

void NightClub::addNarga(const char* filename) {
	if (nargaCount >= Constraints::MAX_NARGAS) {
		throw std::runtime_error("Too much baloons!");
	}
	nargas[nargaCount].createNargaFromFile(filename);
	size_t currCount = nargas[nargaCount].getCount();
	if (currCount == 0) {
		nargaCount++;
	}
	nargas[nargaCount].setCount(currCount + 1);
}

void NightClub::addAlchohol(const char* filename) {
	if (alchoholCount >= Constraints::MAX_ALCHOHOL) {
		throw std::runtime_error("Too much baloons!");
	}

	alchohols[alchoholCount].createAlchoholByFile(filename);
	size_t currCount = alchohols[alchoholCount].getCount();
	if (currCount == 0) {
		alchoholCount++;
	}
	alchohols[alchoholCount].setCount(currCount + 1);
}

void NightClub::removeBaloonByColour(const char* colour) {
	int ind = -1;
	for (int i = 0; i < baloonCount; i++) {
		if (strcmp(baloons[i].getTextFromColur(baloons[i].getColour()), colour) == 0) {
			ind = i;
			break;
		}
	}
	if (ind != -1) {
		for (int i = ind + 1; i < baloonCount; i++) {
			baloons[i - 1] = baloons[i];
		}
	}
	baloonCount--;
}

void NightClub::removeNargaByTasteBrand(const char* brand, const char* taste) {
	int ind = -1;
	for (int i = 0; i < nargaCount; i++) {
		if (strcmp(nargas[i].getBrand(), brand) == 0) {
			if (strcmp(nargas[i].getTextFromTaste(nargas[i].getTaste()), taste) == 0) {
				ind = i;
				break;
			}
		}
	}

	for (int i = ind + 1; i < nargaCount; i++) {
		nargas[i - 1] = nargas[i];
	}
	nargaCount--;
}

void NightClub::removeAlchoholByBrand(const char* brand) {
	int ind = -1;
	for (int i = 0; i < alchoholCount; i++) {
		if (strcmp(alchohols[i].getName(), brand)) {
			ind = i;
			break;
		}
	}

	for (int i = ind + 1; i < alchoholCount; i++) {
		alchohols[i - 1] = alchohols[i];
	}
	alchoholCount--;
}