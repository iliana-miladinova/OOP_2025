#include "Restaurant.h"
#pragma warning(disable:4996)

void Restaurant::resize(unsigned newCap) {
	MyString* temp = new MyString[newCap];
	for (int i = 0; i < currCount; i++) {
		temp[i] = products[i];
	}
	delete[] products;
	products = temp;
	capacity = newCap;
}

void Restaurant::copyFrom(const Restaurant& other) {
	strcpy(name, other.name);
	products = new MyString[other.capacity];
	for (int i = 0; i < other.capacity; i++) {
		products[i] = other.products[i];
	}
	capacity = other.capacity;
	currCount = other.currCount;
}

void Restaurant::moveFrom(Restaurant&& other) {
	strcpy(name, other.name);
	products = other.products;
	other.products = nullptr;
	currCount = other.currCount;
	capacity = other.capacity;
}

void Restaurant::free() {
	delete[] products;
}

bool Restaurant::offersProduct(const MyString& product) const {
	for (int i = 0; i < currCount; i++) {
		if (products[i] == product) {
			return true;
		}
	}
	return false;
}

Restaurant::Restaurant(const char* name, unsigned cap) {
	if (!name) {
		throw std::invalid_argument("Nullptr");
	}

	strncpy(this->name, name, MAX_NAME_LEN+1);
	this->name[25] = '\0';
	products = new MyString[cap];
	capacity = cap;
	currCount = 0;
}

Restaurant::Restaurant() :Restaurant("", 8) {

}

Restaurant::Restaurant(const Restaurant& other) {
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept {
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Restaurant::~Restaurant() {
	free();
}

void Restaurant::addProduct(const MyString& product) {
	if (currCount == capacity) {
		resize(capacity * 2);
	}
	products[currCount++] = product;
}

void Restaurant::receiveOrder(const Order& order) const {
	if (strcmp(name, order.getRestaurantName()) != 0) {
		throw std::invalid_argument("No such order for this restaurant");
		
	}

	for (int i = 0; i < order.getProductsCount(); i++) {
		if (!offersProduct(order.getProducts()[i])) {
			throw std::invalid_argument("A product from the order is not offered by this restaurant");
		}
		
	}
	std::cout << "Order received!" << std::endl;
}

const char* Restaurant::getName() const {
	return name;
}