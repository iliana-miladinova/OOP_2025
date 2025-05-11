#include "Foodpanda.h"
#pragma warning(disable:4996)

void Foodpanda::resize(unsigned newCap) {
	Restaurant* temp = new Restaurant[newCap];
	for (int i = 0; i < currCount; i++) {
		temp[i] = restaurants[i];
	}
	delete[] restaurants;
	restaurants = temp;
	capacity = newCap;
}

void Foodpanda::copyFrom(const Foodpanda& other) {
	restaurants = new Restaurant[other.capacity];
	for (int i = 0; i < other.currCount; i++) {
		restaurants[i] = other.restaurants[i];
	}

	currCount = other.currCount;
	capacity = other.capacity;
}

void Foodpanda::moveFrom(Foodpanda&& other) {
	restaurants = other.restaurants;
	other.restaurants = nullptr;
	currCount = other.currCount;
	capacity = other.capacity;
}

void Foodpanda::free() {
	delete[] restaurants;
}

Foodpanda::Foodpanda(unsigned cap) :capacity(cap), currCount(0) {
	restaurants = new Restaurant[cap];
}

Foodpanda::Foodpanda(const Foodpanda& other)
{
	copyFrom(other);
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Foodpanda::Foodpanda(Foodpanda&& other) noexcept
{
	moveFrom(std::move(other));
}

Foodpanda& Foodpanda::operator=(Foodpanda&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Foodpanda::~Foodpanda()
{
	free();
}

int Foodpanda::findRestIndByName(const char* name) const {
	int ind = -1;
	for (int i = 0; i < currCount; i++) {
		if (strcmp(restaurants[i].getName(), name) == 0) {
			ind = i;
		}
	}
	return ind;
}

void Foodpanda::addProductToRest(const MyString& product, Restaurant& rest) {
	int ind = findRestIndByName(rest.getName());
	if (ind == -1) {
		throw std::invalid_argument("Restaurant not found");
	}
	restaurants[ind].addProduct(product);
}

void Foodpanda::addRestaurant(const Restaurant& rest) {
	if (currCount == capacity) {
		resize(capacity * 2);
	}
	restaurants[currCount++] = rest;
}

void Foodpanda::addOrderToRest(const Order& order) {
	int ind = findRestIndByName(order.getRestaurantName());
	if (ind == -1) {
		throw std::invalid_argument("Restaurant with this order not found");
	}
	restaurants[ind].receiveOrder(order);
}