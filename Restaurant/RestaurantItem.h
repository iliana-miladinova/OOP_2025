#pragma once
#include <iostream>

enum ProductType {
	DEFAULT,
	FOOD, 
	DRINK	
};

class RestaurantItem {
private:
	ProductType productType; //= ProductType::DEFAULT;
	unsigned quantity = 0;
	double price = 0.0;
	char* name = nullptr;

	void copyFrom(const RestaurantItem& other);
	void moveFrom(RestaurantItem&& other);
	void free();

public:
	ProductType getProductType() const;
	unsigned getQuantity() const;
	double getPrice() const;
	const char* getName() const;

	void setProductType(ProductType prType);
	void setQuantity(unsigned quantity);
	void setPrice(double price);
	void setName(const char* name);

	RestaurantItem() = default;
	RestaurantItem(ProductType prType, unsigned quantity, double price, const char* name);

	RestaurantItem(const RestaurantItem& other);
	RestaurantItem& operator=(const RestaurantItem& other);

	RestaurantItem(RestaurantItem&& other) noexcept;
	RestaurantItem& operator=(RestaurantItem&& other) noexcept;

	virtual void print() const = 0;

	virtual ~RestaurantItem();

	virtual RestaurantItem* clone() const = 0;
};