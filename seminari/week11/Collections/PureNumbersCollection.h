#pragma once
#include "DynamicCollection.h"

class PureNumbersCollection :public DynamicCollection {
public:
	virtual PureNumbersCollection* clone() const = 0;
	virtual ~PureNumbersCollection() = default;
};