#pragma once
#include <iostream>

template <typename T>
class Matrix {
private:
	T** mtx;
	unsigned rowsNum;
	unsigned colsNum;

	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	void free();

	void createMatrix(unsigned rowsNum, unsigned colsNum);

public:
	Matrix();
	Matrix(unsigned rowsNum, unsigned colsNum);
	Matrix(const Matrix& other);
	Matrix<T>& operator=(const Matrix& other);

	Matrix(Matrix&& other) noexcept;
	Matrix<T>& operator=(Matrix&& other) noexcept;

	~Matrix();

	void setAt(unsigned x, unsigned y, T element);

	const T& getAt(unsigned x, unsigned y) const;
	T& getAT(unsigned x, unsigned y);
	void transpose();
};

template <typename T>
void Matrix<T>::createMatrix(unsigned rowsNum, unsigned colsNum) {
	this->rowsNum = rowsNum;
	this->colsNum = colsNum;

	mtx = new T* [rowsNum];
	for (size_t i = 0; i < rowsNum; i++)
	{
		mtx[i] = new T[colsNum];
	}
}

template <typename T>
Matrix<T>::Matrix() {
	createMatrix(2, 2);
}

template <typename T>
Matrix<T>::Matrix(unsigned rowsNum, unsigned colsNum) {
	createMatrix(rowsNum, colsNum);
}

template <typename T>
void Matrix<T>::copyFrom(const Matrix& other) {
	createMatrix(other.rowsNum, other.colsNum);
	for (size_t i = 0; i < rowsNum; i++)
	{
		for (size_t j = 0; j < colsNum; j++)
		{
			mtx[i][j] = other.mtx[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::free() {
	for (size_t i = 0; i < rowsNum; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

template <typename T>
void Matrix<T>::moveFrom(Matrix&& other) {
	mtx = other.mtx;
	other.mtx = nullptr;

	rowsNum = other.rowsNum;
	colsNum = other.colsNum;

	other.colsNum = other.rowsNum = 0;
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) {
	copyFrom(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
	if (this!=other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
	free();
}

template <typename T>
void Matrix<T>::setAt(unsigned x, unsigned y, T element) {
	x--;
	y--;
	if (x>=rowsNum || y>=colsNum)
	{
		throw std::out_of_range("Invalid x or y");
	}
	mtx[x][y] = element;
}

template <typename T>
const T& Matrix<T>::getAt(unsigned x, unsigned y) const{
	x--;
	y--;
	if (x>=rowsNum || y>=colsNum)
	{
		throw std::out_of_range("Invalid x or y"); 
	}
	return mtx[x][y];
}

template <typename T>
T& Matrix<T>::getAT(unsigned x, unsigned y) {
	x--;
	y--;
	if (x >= rowsNum || y >= colsNum)
	{
		throw std::out_of_range("Invalid x or y");
	}
	return mtx[x][y];
}

template <typename T>
void Matrix<T>::transpose() {
	T** newMtx = new T * [colsNum];
	for (size_t i = 0; i < colsNum; i++)
	{
		newMtx[i] = new T[rowsNum];
		for (size_t j = 0; j < rowsNum; j++)
		{
			newMtx[i][j] = mtx[j][i];
		}
	}
	free();
	mtx = newMtx;
	std::swap(rowsNum, colsNum);
}