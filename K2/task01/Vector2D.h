#pragma once
#include <iostream>

class Vector2D {
private:
	double x = 0.0;
	double y = 0.0;

public:
	Vector2D() = default;
	Vector2D(double x, double y);
	friend Vector2D operator*(double num, const Vector2D& v);

	Vector2D& operator+=(const Vector2D& v2);

	double getX() const;
	double getY() const;
};

Vector2D operator*(const Vector2D& v, double num);
Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
double operator^(const Vector2D& v1, const Vector2D& v2);
bool operator==(const Vector2D& v1, const Vector2D& v2);
bool operator!=(const Vector2D& v1, const Vector2D& v2);