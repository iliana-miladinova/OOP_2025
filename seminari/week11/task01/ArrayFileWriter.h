#pragma once
#include "FileWriter.h"
#include <fstream>

class ArrayFileWriter :public FileWriter {
public:
	ArrayFileWriter(const MyString& fileName);
	void write(const int* arr, size_t size) const override;
};