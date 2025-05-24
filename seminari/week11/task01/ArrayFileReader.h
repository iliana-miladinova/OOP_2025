#pragma once
#include "FileReader.h"
#include "HelperFunctions.h"
#include <fstream>


class ArrayFileReader :public FileReader {
public:
	ArrayFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};