#include "RestaurantItem.h"
#pragma warning(disable:4996)

ProductType RestaurantItem::getProductType() const {
	return productType;
}

unsigned RestaurantItem::getQuantity() const {
	return quantity;
}

double RestaurantItem::getPrice() const {
	return price;
}

const char* RestaurantItem::getName() const {
	return name;
}

void RestaurantItem::setName(const char* name) {
	if (!name || this->name == name)
	{
		return;
	}
	if (this->name)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void RestaurantItem::setProductType(ProductType prType) {
	productType = prType;
}

void RestaurantItem::setQuantity(unsigned quantity) {
	this->quantity = quantity;
}

void RestaurantItem::setPrice(double price) {
	this->price = price;
}

RestaurantItem::RestaurantItem(ProductType prType, unsigned quantity, double price, const char* name) {
	setProductType(prType);
	setQuantity(quantity);
	setPrice(price);
	setName(name);
}

void RestaurantItem::copyFrom(const RestaurantItem& other) {
	setName(other.name);
	setProductType(other.productType);
	setQuantity(other.quantity);
	setPrice(other.price);
}

void RestaurantItem::moveFrom(RestaurantItem&& other) {
	name = other.name;
	other.name = nullptr;

	productType = other.productType;
	other.productType = ProductType::DEFAULT;

	quantity = other.quantity;
	other.quantity = 0;
	price = other.price;
	other.price = 0;
}

void RestaurantItem::free() {
	delete[] name;
}

RestaurantItem::RestaurantItem(const RestaurantItem& other) {
	copyFrom(other);
}

RestaurantItem& RestaurantItem::operator=(const RestaurantItem& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

RestaurantItem::RestaurantItem(RestaurantItem&& other) noexcept {
	moveFrom(std::move(other));
}

RestaurantItem& RestaurantItem::operator=(RestaurantItem&& other) noexcept {
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

RestaurantItem::~RestaurantItem() {
	free();
}