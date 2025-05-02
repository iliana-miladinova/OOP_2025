#include "Alchohol.h"

void Alchohol::setName(const char* alcName) {
	if (!alcName) {
		throw std::invalid_argument("Nullptr");
	}
	if (strlen(alcName) > MAX_LEN) {
		throw std::length_error("Too big");
		
	}
	strcpy(name, alcName);
}

void Alchohol::setPrice(double alcPrice) {
	price = alcPrice;
}

const char* Alchohol::getName() const {
	return name;
}

double Alchohol::getPrice() const {
	return price;
}

Alchohol::Alchohol() {
	setName("");
	setPrice(0);
}

Alchohol::Alchohol(const char* alcName, double alcPrice) {
	setName(alcName);
	setPrice(alcPrice);
}

size_t Alchohol::getCount() const {
	return count;
}

void Alchohol::setCount(size_t count) {
	this->count = count;
}

void Alchohol::createAlchoholByFile(const char* filename) {
	std::ifstream ifs(filename);

	if (!ifs.is_open()) {
		throw std::exception("Cannot open file for reading");
	}

	char buff[1024];
	ifs.getline(buff, sizeof(buff));

	std::stringstream ss(buff);
	char brandname[MAX_LEN + 1];

	ss.getline(brandname, MAX_LEN + 1, '-');
	setName(brandname);

	double alcprice;
	ss >> alcprice;
	setPrice(alcprice);

	ifs.close();
}