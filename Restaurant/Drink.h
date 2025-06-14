#pragma once
#include "RestaurantItem.h"

class Drink :public RestaurantItem {
private:
	double alchohol = 0.0;

public:
	Drink() = default;
	Drink(unsigned quantity, double price, const char* name, double alchohol);

	void setAlchohol(double alchohol);

	double getAlchohol() const;

	friend bool operator>(const Drink& lhs, const Drink& rhs);

	void print() const override;

	RestaurantItem* clone() const override;
};

