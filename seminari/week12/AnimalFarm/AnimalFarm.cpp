#include "AnimalFarm.h"
#include "AnimalFactory.h"

static constexpr size_t INITIAL_CAP = 16;

AnimalFarm::AnimalFarm() :capacity(INITIAL_CAP) {
	animals = new Animal * [capacity];
}

void AnimalFarm::copyFrom(const AnimalFarm& other) {
	animals = new Animal * [other.capacity];
	for (size_t i = 0; i < other.capacity; i++)
	{
		animals[i] = other.animals[i]->clone();
	}
	animalsCount = other.animalsCount;
	capacity = other.capacity;
}

void AnimalFarm::moveFrom(AnimalFarm&& other) noexcept {
	animals = other.animals;
	other.animals = nullptr;
	animalsCount = other.animalsCount;
	capacity = other.capacity;
	other.animalsCount = other.capacity = 0;
}

void AnimalFarm::free() {
	for (size_t i = 0; i < animalsCount; i++)
	{
		delete animals[i];
	}
	delete[] animals;
	animals = nullptr;
	animalsCount = capacity = 0;
}

void AnimalFarm::resize(size_t newCap) {
	Animal** resized = new Animal * [newCap];
	for (size_t i = 0; i < animalsCount; i++)
	{
		resized[i] = animals[i];
	}
	delete[] animals;
	animals = resized;
	capacity = newCap;
}

AnimalFarm::AnimalFarm(const AnimalFarm& other) {
	copyFrom(other);
}

AnimalFarm::AnimalFarm(AnimalFarm&& other) noexcept {
	moveFrom(std::move(other));
}

AnimalFarm& AnimalFarm::operator=(const AnimalFarm& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

AnimalFarm& AnimalFarm::operator=(AnimalFarm&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

AnimalFarm::~AnimalFarm() {
	free();
}

void AnimalFarm::addAnimal(AnimalType animalType) {
	if (animalsCount >= capacity) {
		resize(capacity * 2);
	}
	animals[animalsCount++] = animalFactory(animalType);
}

void AnimalFarm::addAnimal(const Animal& animal) {
	if (animalsCount >= capacity) {
		resize(capacity * 2);
	}
	animals[animalsCount++] = animal.clone();
}

void AnimalFarm::addAnimal(Animal* animal) {
	if (animalsCount >= capacity) {
		resize(capacity * 2);
	}
	animals[animalsCount++] = animal;
}

void AnimalFarm::wakeUpAnimals() const {
	for (size_t i = 0; i < animalsCount; i++)
	{
		animals[i]->makeSound();
	}
}