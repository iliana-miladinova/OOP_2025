#include "Guest.h"

Guest::Guest(unsigned time) :Player(), time(time) {

}

bool Guest::levelUp() {
	std::cout << "You are a guest and cant win stars" << std::endl;
	return false;
}
