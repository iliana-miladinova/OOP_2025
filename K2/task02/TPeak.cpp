#include "TPeak.h"
#pragma warning(disable:4996)

void TPeak::setPeakName(const char* name) {
	if (!name || name == peakName) {
		return;
	}

	if (peakName) {
		delete[] peakName;
	}

	peakName = new char[strlen(name) + 1];
	strcpy(peakName, name);
}
TPeak::TPeak() :Peak(), peakName(nullptr) {

}

TPeak::TPeak(double height, const char* _mountainName, const char* _peakName) :Peak(height, _mountainName) {
	setPeakName(_peakName);
}

void TPeak::copyFrom(const TPeak& other) {
	setPeakName(other.peakName);
}

void TPeak::moveFrom(TPeak&& other) {
	peakName = other.peakName;
	other.peakName = nullptr;
}

void TPeak::free() {
	delete[] peakName;
}

TPeak::TPeak(const TPeak& other) : Peak(other) {
	copyFrom(other);
}

TPeak& TPeak::operator=(const TPeak& other) {
	if (this != &other) {
		Peak::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

TPeak::TPeak(TPeak&& other) noexcept :Peak(std::move(other)) {
	moveFrom(std::move(other));
}

TPeak& TPeak::operator=(TPeak&& other) noexcept {
	if (this!=&other)
	{
		Peak::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

TPeak::~TPeak() {
	free();
}

void TPeak::printPeakName() const {
	std::cout << "Peak: " << peakName << std::endl;
}