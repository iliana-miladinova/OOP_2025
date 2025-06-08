#include "AnimalFactory.h"
#include "Cow.h"
#include "Pig.h"
#include "Dog.h"

Animal* animalFactory(AnimalType animalType) {
	switch (animalType)
	{
	case AnimalType::COW:
		return new Cow();
	case AnimalType::PIG:
		return new Pig();
	case AnimalType::DOG:
		return new Dog();
	}
	return nullptr;
}