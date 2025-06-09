#pragma once
#include "Bitset.h"

class SetByCriteria :public Bitset {
public:
	SetByCriteria(unsigned n, bool(*criteria)(unsigned num));
};