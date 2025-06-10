#pragma once
#include "PureNumbersCollection.h"

class NormalCollection :public PureNumbersCollection {
private:
	int findInd(int num) const;
public:
	void add(int num) override;
	void remove(int num) override;
	size_t count(int num) const override;
	bool contains(int num) const override;

	PureNumbersCollection* clone() const override;
};