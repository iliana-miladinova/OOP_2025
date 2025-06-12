#pragma once
#include "Peak.h"

class MPeak :public Peak {
private:
	int kotaNum;

public:
	MPeak();
	MPeak(double height, const char* mountainName, int kotaNum);

	void printPeakName() const override;
};