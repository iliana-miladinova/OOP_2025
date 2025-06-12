#include "MPeak.h"

MPeak::MPeak() :Peak(), kotaNum(0) {

}

MPeak::MPeak(double height, const char* mountainName, int kotaNum) :Peak(height, mountainName), kotaNum(kotaNum) {

}

void MPeak::printPeakName() const {
	std::cout << "kota " << kotaNum << std::endl;
}