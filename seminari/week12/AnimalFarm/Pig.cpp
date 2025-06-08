#include "Pig.h"

Pig::Pig() : Animal(AnimalType::PIG) {

}

void Pig::makeSound() const {
	std::cout << "Gruh gruh!" << std::endl;
}

Animal* Pig::clone() const {
	return new Pig(*this);
}