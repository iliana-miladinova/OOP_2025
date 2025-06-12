#pragma once
#include "Peak.h"

class TPeak :public Peak {
private:
	char* peakName;

	void copyFrom(const TPeak& other);
	void moveFrom(TPeak&& other);
	void free();

	void setPeakName(const char* name);
public:
	TPeak();
	TPeak(double height, const char* mountainName, const char* peakName);

	TPeak(const TPeak& other);
	TPeak& operator=(const TPeak& other);

	TPeak(TPeak&& other) noexcept;
	TPeak& operator=(TPeak&& other) noexcept;

	~TPeak();

	void printPeakName() const override;
};