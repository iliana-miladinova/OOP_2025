#include "Cow.h"

Cow::Cow():Animal(AnimalType::COW) {

}

void Cow::makeSound() const {
	std::cout << "Mooo!" << std::endl;
}

Animal* Cow::clone() const {
	return new Cow(*this);
}