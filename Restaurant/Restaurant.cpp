#include "Restaurant.h"
#include "ItemFactory.h"
#include "Drink.h"

void Restaurant::copyFrom(const Restaurant& other) {
	cap = other.cap;
	size = other.size;
	items = new RestaurantItem * [cap];
	for (size_t i = 0; i < size; i++)
	{
		items[i] = other.items[i]->clone();
	}
}

void Restaurant::moveFrom(Restaurant&& other) {
	items = other.items;
	other.items = nullptr;

	size = other.size;
	cap = other.cap;
	other.size = other.cap = 0;
}

void Restaurant::free() {
	for (size_t i = 0; i < size; i++)
	{
		delete[] items[i];
	}
	delete[] items;
	items = nullptr;
	size = cap = 0;
}

void Restaurant::resize(size_t newCap) {
	RestaurantItem** resized = new RestaurantItem * [newCap];
	for (size_t i = 0; i < size; i++)
	{
		resized[i] = items[i];
	}
	delete[] items;
	items = resized;
	cap = newCap;
}

Restaurant::Restaurant() {
	items = new RestaurantItem * [cap];
}

Restaurant::Restaurant(const Restaurant& other)
{
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Restaurant::~Restaurant()
{
	free();
}

void Restaurant::addProduct(const RestaurantItem& product) {
	if (size == cap) {
		resize(cap * 2);
	}

	items[size++] = product.clone();
}

void Restaurant::addProduct(RestaurantItem* item) {
	if (size==cap)
	{
		resize(cap * 2);
	}
	items[size++] = item;
}

void Restaurant::addProduct(ProductType type) {
	if (size==cap)
	{
		resize(cap * 2);
	}
	items[size++] = itemFactory(type);
}

void Restaurant::removeProduct(size_t ind) {
	if (ind>=size)
	{
		throw std::invalid_argument("Invalid ind");
	}
	std::swap(items[ind], items[size - 1]);
	delete items[size - 1];
	items[size - 1] = nullptr;
	size--;
}

void Restaurant::modifyPrice(size_t ind, double newPrice) {
	if (ind >= size)
	{
		throw std::invalid_argument("Invalid ind");
	}
	items[ind]->setPrice(newPrice);
}

void Restaurant::modifyName(size_t ind, const char* newName) {
	if (ind >= size)
	{
		throw std::invalid_argument("Invalid ind");
	}
	items[ind]->setName(newName);
}

void Restaurant::printAll() const {
	for (size_t i = 0; i < size; i++)
	{
		items[i]->print();
	}
}

void Restaurant::printNonAlchoholicDrinks() const {
	for (size_t i = 0; i < size; i++)
	{
		if (items[i]->getProductType()==ProductType::DRINK)
		{
			//const Drink* drink = dynamic_cast<const Drink*>(items[i]);
			Drink* drink = (Drink*)items[i];
			if (drink->getAlchohol()==0)
			{
				drink->print();
			}
		}
	}
}