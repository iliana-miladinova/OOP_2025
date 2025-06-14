#pragma once
#include "RestaurantItem.h"

class Restaurant {
private:
	RestaurantItem** items = nullptr;
	size_t size = 0;
	size_t cap = 8;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();
	void resize(size_t newCap);

public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void addProduct(const RestaurantItem& product);

	//other 
	void addProduct(ProductType type);
	void addProduct(RestaurantItem* item);

	void removeProduct(size_t ind);
	void modifyPrice(size_t ind, double newPrice);
	void modifyName(size_t ind, const char* newName);
	void printAll() const;
	void printNonAlchoholicDrinks() const;
};