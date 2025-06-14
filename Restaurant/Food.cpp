#include "Food.h"

RestaurantItem* Food::clone() const {
	return new Food(*this);
}

void Food::setWeight(double weight) {
	this->weight = weight;
}

Food::Food(unsigned quantity, double price, const char* name, double weight) : RestaurantItem(ProductType::FOOD, quantity, price, name)	{
	setWeight(weight);
}

bool operator>(const Food& lhs, const Food& rhs) {
	return lhs.weight > rhs.weight;
}

void Food::print() const {
	std::cout << getName() << " " << getQuantity() << " " << getPrice() << " " << weight << std::endl;
}