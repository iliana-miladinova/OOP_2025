#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <sstream>

constexpr size_t MAX_LEN = 128;

class Alchohol {
private:
	char name[MAX_LEN+1];
	double price;
	size_t count = 0;

public:
	Alchohol();
	Alchohol(const char* alcName, double alcPrice);

	void setName(const char* alcName);
	void setPrice(double alcPrice);
	void setCount(size_t count);

	const char* getName() const;
	double getPrice() const;
	size_t getCount() const;

	void createAlchoholByFile(const char* filename);
};
