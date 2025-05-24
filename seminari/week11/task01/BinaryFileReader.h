#pragma once
#include <fstream>
#include "FileReader.h"
#include "HelperFunctions.h"

class BinaryFileReader :public FileReader {
public:
	BinaryFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};