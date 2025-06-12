#include "Peak.h"
#pragma warning(disable:4996)

void Peak::setMountainName(const char* name) {
	if (!name ||name==this->mountainName)
	{
		return;
	}

	if (this->mountainName) {
		delete[] mountainName;
	}

	mountainName = new char[strlen(name) + 1];
	strcpy(this->mountainName, name);
}

Peak::Peak(double h, const char* name) :height(h) {
	setMountainName(name);
}

Peak::Peak() :height(0.0), mountainName(nullptr) {
	
}

void Peak::copyFrom(const Peak& other) {
	height = other.height;
	setMountainName(other.mountainName);
}

void Peak::moveFrom(Peak&& other) {
	mountainName = other.mountainName;
	other.mountainName = nullptr;

	height = other.height;
	other.height = 0;
}

void Peak::free() {
	delete[] mountainName;
}

Peak::Peak(const Peak& other) {
	copyFrom(other);
}

Peak& Peak::operator=(const Peak& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Peak::Peak(Peak&& other) noexcept {
	moveFrom(std::move(other));
}

Peak& Peak::operator=(Peak&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Peak::~Peak() {
	free();
}

double Peak::getHeight() const 
{
	return height;
}

const char* Peak::getMountainName() const {
	return mountainName;
}