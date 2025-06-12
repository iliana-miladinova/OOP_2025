#pragma once
#include <iostream>

class Peak {
private:
	double height;
	char* mountainName;

	void copyFrom(const Peak& other);
	void moveFrom(Peak&& other);
	void free();

	void setMountainName(const char* name);
public:
	Peak();
	Peak(double h, const char* name);

	Peak(const Peak& other);
	Peak& operator=(const Peak& other);

	Peak(Peak&& other) noexcept;
	Peak& operator=(Peak&& other) noexcept;

	virtual ~Peak();

	double getHeight() const;
	const char* getMountainName() const;
	virtual void printPeakName() const = 0;
};