#pragma once
#include <iostream>
#include "Taste.h"
#include <fstream>
#include <sstream>
#pragma warning(disable: 4996)

constexpr size_t BRAND_LEN = 1024;

class Narga {
private:
	double price;
	char brand[BRAND_LEN];
	Taste taste;
	size_t count = 0;

	//const char* getTextFromTaste(Taste taste) const;
	Taste getTasteFromInd(int ind) const;

public:
	void getInputFromConsole();
	void print() const;

	Narga();
	Narga(double price, const char* brand, Taste taste);

	void setPrice(double price);
	void setBrand(const char* brand);
	void setTaste(Taste taste);
	void setCount(size_t count);

	double getPrice() const;
	const char* getBrand() const;
	Taste getTaste() const;
	size_t getCount() const;
	const char* getTextFromTaste(Taste taste) const;
	Taste getTasteFromText(const char* text) const;

	void createNargaFromFile(const char* filename);
};