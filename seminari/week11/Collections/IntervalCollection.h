#pragma once
#include "DynamicCollection.h"

class IntervalCollection :public DynamicCollection {
private:
	int start;
	int end;

public:
	IntervalCollection(int start, int end);

	unsigned intervalLen() const;

	void add(int num) override;
	void remove(int num) override;
	size_t count(int num) const override;
	bool contains(int num) const override;
};