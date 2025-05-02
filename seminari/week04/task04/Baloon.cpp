#include "Baloon.h"

void Baloon::setPrice(double price) {
	this->price = price;
}

void Baloon::setColour(Colour colour) {
	this->colour = colour;
}

double Baloon::getPrice() const {
	return this->price;
}

Colour Baloon::getColour() const {
	return this->colour;
}

Baloon::Baloon() {
	setPrice(0);
	setColour(Colour::Unknown);
}

Baloon::Baloon(double price, Colour colour) {
	setPrice(price);
	setColour(colour);
}

Colour Baloon::getColourByText(const char* text) {
	if (strcmp(text, "white") == 0) {
		return Colour::White;
	}
	if (strcmp(text, "green") == 0) {
		return Colour::Green;
	}
	if (strcmp(text, "red") == 0) {
		return Colour::Red;
	}
	else {
		return Colour::Unknown;
	}
}

void Baloon::createBaloonFromFile(const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		throw std::exception("Cannot open file for reading");
	}

	char buff[1024];
	
	ifs.getline(buff, sizeof(buff));

	std::stringstream ss(buff);  //prevrashta reda v potok

	char baloonColour[8];
	ss.getline(baloonColour, 8, '-');
	Colour c = getColourByText(baloonColour);
	setColour(c);

	double price;
	ss >> price;
	setPrice(price);

	ifs.close();
}

const char* Baloon::getTextFromColur(const Colour& c) const {
	switch (c)
	{
	case Colour::White: return "White";
	case Colour::Green: return "Green";
	case Colour::Red: return "Red";
	case Colour::Unknown: return "Unknown";
	}
}

void Baloon::setCount(size_t count) {
	this->count = count;
}

size_t Baloon::getCount() const {
	return count;
}