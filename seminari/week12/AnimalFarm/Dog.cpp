#include "Dog.h"

Dog::Dog() : Animal(AnimalType::DOG) {

}

void Dog::makeSound() const {
	std::cout << "Bau bau" << std::endl;
}

Animal* Dog::clone() const {
	return new Dog(*this);
}