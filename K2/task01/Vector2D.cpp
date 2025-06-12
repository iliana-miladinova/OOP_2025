#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) :x(x), y(y) {

}

Vector2D operator*(double num, const Vector2D& v) {
	Vector2D res;

	res.x = num * v.x;
	res.y = num * v.y;
	return res;
}

Vector2D operator*(const Vector2D& v, double num) {
	return operator*(num, v);
}

Vector2D& Vector2D::operator+=(const Vector2D& v2) {
	this->x += v2.x;
	this->y += v2.y;
	return *this;
}

Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
	Vector2D res(v1);
	res += v2;
	return res;
}

double Vector2D::getX() const {
	return x;
}

double Vector2D::getY() const {
	return y;
}


double operator^(const Vector2D& v1, const Vector2D& v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

bool operator==(const Vector2D& v1, const Vector2D& v2) {
	return v1.getX() == v2.getX() && v1.getY() == v2.getY();
}

bool operator!=(const Vector2D& v1, const Vector2D& v2) {
	return !(operator==(v1, v2));
}