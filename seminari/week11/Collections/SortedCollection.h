#pragma once
#include "PureNumbersCollection.h"

class SortedCollection :public PureNumbersCollection {
private:
	int lowerBound(int num) const;
	int upperBound(int num) const;

public:
	void add(int num) override;
	void remove(int num) override;
	size_t count(int num) const override;
	bool contains(int num) const override;

	PureNumbersCollection* clone() const override;
};