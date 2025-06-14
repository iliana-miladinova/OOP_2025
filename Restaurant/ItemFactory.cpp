#include "ItemFactory.h"
#include "Food.h"
#include "Drink.h"

RestaurantItem* itemFactory(ProductType pr) {
	switch (pr)
	{
	case ProductType::FOOD:
		return new Food();
	case ProductType::DRINK:
		return new Drink();
	}
	return nullptr;
}