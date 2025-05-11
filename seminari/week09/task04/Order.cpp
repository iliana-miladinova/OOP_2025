#include "Order.h"
#pragma warning(disable:4996)

void Order::resize(unsigned newCap) {
	MyString* newOrd = new MyString[newCap];
	for (int i = 0; i < productsCount; i++) {
		newOrd[i] = products[i];
	}
	delete[] products;
	products = newOrd;
	capacity = newCap;
}

void Order::copyFrom(const Order& other) {
	restaurantName = new char[strlen(other.restaurantName)+1];
	strcpy(restaurantName, other.restaurantName);

	products = new MyString[other.capacity];
	for (int i = 0; i < other.productsCount; i++) {
		products[i] = other.products[i];
	}
	
	capacity = other.capacity;
	productsCount = other.productsCount;
	productsLen = other.productsLen;
}

void Order::moveFrom(Order&& other) {
	restaurantName = other.restaurantName;
	other.restaurantName = nullptr;

	products = other.products;
	other.products = nullptr;

	productsCount = other.productsCount;
	capacity = other.capacity;
	productsLen = other.productsLen;
}

void Order::free() {
	delete[] restaurantName;
	delete[] products;
}

Order::Order() :Order("") {
}

Order::Order(const char* rest) {
	if (!rest) {
		throw std::invalid_argument("Nullptr");
	}
	restaurantName = new char[strlen(rest) + 1];
	strcpy(restaurantName, rest);
	productsCount = 0;
	capacity = 8;
	products = new MyString[capacity];
	productsLen = 0;
}

Order::Order(const Order& other) {
	copyFrom(other);
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Order::Order(Order&& other) noexcept {
	moveFrom(std::move(other));
}

Order& Order::operator=(Order&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Order::~Order() {
	free();
}

void Order::addProduct(const MyString& product) {
	if (productsCount == capacity) {
		resize(capacity * 2);
	}
	products[productsCount++] = product;
	productsLen += product.len();
}

int Order::getDeliveryTime() const {
	return productsCount + productsLen;
}

const char* Order::getRestaurantName() const {
	return restaurantName;
}

unsigned Order::getProductsCount() const {
	return productsCount;
}

const MyString* Order::getProducts() const {
	return products;
}