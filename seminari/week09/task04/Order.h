#pragma once
#include <iostream>
#include "MyString.h"

class Order {
public:
	Order();
	Order(const char* rest);

	Order(const Order& other);
	Order& operator=(const Order& other);

	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;

	~Order();

	void addProduct(const MyString& product);
	int getDeliveryTime() const;

	const char* getRestaurantName() const;
	unsigned getProductsCount() const;
	const MyString* getProducts() const;

private:
	char* restaurantName;
	unsigned productsCount;
	MyString* products;
	unsigned capacity;
	unsigned productsLen;

	void resize(unsigned newCap);
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);
	void free();
};