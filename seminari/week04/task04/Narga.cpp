#include "Narga.h"

void Narga::getInputFromConsole() {
	std::cin >> this->price;
	std::cin >> this->brand;
	int tasteInd;
	std::cin >> tasteInd;
	this->taste = getTasteFromInd(tasteInd);
}

Taste Narga::getTasteFromInd(int ind) const {
	switch (ind) {
	case 0: return Taste::Blueberry;
	case 1: return Taste::Queen;
	case 2: return Taste::Mango;
	case 3: return Taste::Strawberry;
	case 4: return Taste::Banana;
	default:
		return Taste::Unknown;
	}
}

const char* Narga::getTextFromTaste(Taste taste) const {
	switch (taste)
	{
	case Taste::Blueberry:
		return "Blueberry";
	case Taste::Queen:
		return "Queen";
	case Taste::Mango:
		return "Mango";
	case Taste::Strawberry:
		return "Strawberry";
	case Taste::Banana:
		return "Banana";
	default:
		return "Unknown";
	}
}

void Narga::print() const {
	std::cout << this->price << " " << this->brand << " " << getTextFromTaste(this->taste) << std::endl;;
}

Narga::Narga() {
	setPrice(0);
	setBrand("");
	setTaste(Taste::Unknown);
}

Narga::Narga(double price, const char* brand, Taste taste) {
	setPrice(price);
	setBrand(brand);
	setTaste(taste);
}

void Narga::setPrice(double price) {
	this->price = price;
}

void Narga::setBrand(const char* brand) {
	unsigned brandLen = strlen(brand);
	if (brandLen > BRAND_LEN) {
		std::cout << "Too long name";
		return;
	}
	strcpy(this->brand, brand);
}

void Narga::setTaste(Taste taste) {
	this->taste = taste;
}

double Narga::getPrice() const {
	return this->price;
}

const char* Narga::getBrand() const {
	return this->brand;
}

Taste Narga::getTaste() const {
	return this->taste;
}

size_t Narga::getCount() const{
	return count;
}

void Narga::setCount(size_t count) {
	this->count = count;
}

Taste Narga::getTasteFromText(const char* text) const {
	if (strcmp(text, "queen") == 0) {
		return Taste::Queen;
	}
	if (strcmp(text, "strawberry") == 0) {
		return Taste::Strawberry;
	}
	if (strcmp(text, "banana") == 0) {
		return Taste::Banana;
	}
	if (strcmp(text, "blueberry") == 0) {
		return Taste::Blueberry;
	}
	if (strcmp(text, "mango") == 0) {
		return Taste::Mango;
	}
	else
	{
		return Taste::Unknown;
	}
}
void Narga::createNargaFromFile(const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		throw std::exception("Cannot open file for reading");
	}

	char buff[1024];
	ifs.getline(buff, sizeof(buff));

	std::stringstream ss(buff);
	char brandName[BRAND_LEN];
	ss.getline(brandName, BRAND_LEN, '-');
	setBrand(brandName);

	char nargaTaste[11];
	ss.getline(nargaTaste, 11, '-');
	Taste t = getTasteFromText(nargaTaste);
	setTaste(t);

	double nargaPrice;
	ss >> price;
	setPrice(nargaPrice);

	ifs.close();
}