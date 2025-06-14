#pragma once
#include "RestaurantItem.h"

class Food :public RestaurantItem {
private:
	double weight = 0.0;
	
public:
	Food() = default;
	void setWeight(double weight);

	Food(unsigned quantity, double price, const char* foodName, double weight);

	friend bool operator>(const Food& lhs, const Food& rhs);

	void print() const override;
	RestaurantItem* clone() const override;
};