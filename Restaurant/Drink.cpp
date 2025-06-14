#include "Drink.h"

void Drink::setAlchohol(double alchohol) {
	this->alchohol = alchohol;
}

Drink::Drink(unsigned quantity, double price, const char* name, double alchohol) :RestaurantItem(ProductType::DRINK, quantity, price, name) {
	setAlchohol(alchohol);
}

bool operator>(const Drink& lhs, const Drink& rhs) {
	return lhs.alchohol > rhs.alchohol;
}

double Drink::getAlchohol() const {
	return alchohol;
}

void Drink::print() const {
	std::cout << getName() << " " << getQuantity() << " " << getPrice() << " " << alchohol<<std::endl;
}

RestaurantItem* Drink::clone() const {
	return new Drink(*this);
}