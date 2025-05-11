#pragma once
#include <iostream>
#include "MyString.h"
#include "Order.h"

constexpr size_t MAX_NAME_LEN = 25;
class Restaurant {
public:
	Restaurant();
	Restaurant(const char* name, unsigned cap);

	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);

	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;

	~Restaurant();

	void addProduct(const MyString& product);
	void receiveOrder(const Order& order) const;

	const char* getName() const;

private:
	char name[MAX_NAME_LEN + 1];
	MyString* products;
	unsigned currCount;
	unsigned capacity;

	void resize(unsigned newCap);
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();
	
	bool offersProduct(const MyString& product) const;
};