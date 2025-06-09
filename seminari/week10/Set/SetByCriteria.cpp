#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool(*criteria)(unsigned num)) :Bitset(n) {
	for (size_t i = 0; i < n; i++)
	{
		if (criteria(i)) {
			add(i);
		}
	}
}