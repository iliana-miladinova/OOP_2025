#pragma once
#include "Restaurant.h"
#include <iostream>

class Foodpanda {
public:
	Foodpanda(unsigned cap);

	Foodpanda(const Foodpanda& other);
	Foodpanda& operator=(const Foodpanda& other);

	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(Foodpanda&& other) noexcept;

	~Foodpanda();

	void addProductToRest(const MyString& product, Restaurant& rest);
	void addRestaurant(const Restaurant& rest);
	void addOrderToRest(const Order& order);
private:
	Restaurant* restaurants;
	unsigned currCount;
	unsigned capacity;

	void resize(unsigned newCap);
	void copyFrom(const Foodpanda& other);
	void moveFrom(Foodpanda&& other);
	void free();

	int findRestIndByName(const char* name) const;
};