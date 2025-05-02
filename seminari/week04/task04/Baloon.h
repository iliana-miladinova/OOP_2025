#pragma once
#include <iostream>
#include "Colour.h"
#include <fstream>
#include <sstream>
#pragma warning(disable:4996)

class Baloon {
private:
	double price;
	Colour colour;
	size_t count = 0;

	Colour getColourByText(const char* text);
public:
	Baloon();
	Baloon(double price, Colour colour);

	void setPrice(double price);
	void setColour(Colour colour);
	void setCount(size_t count);

	double getPrice() const;
	Colour getColour() const;
	const char* getTextFromColur(const Colour& c) const;
	size_t getCount() const;

	void createBaloonFromFile(const char* filename);
};