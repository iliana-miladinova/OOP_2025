#pragma once
#include <fstream>
#include "FileReader.h"
#include "HelperFunctions.h"

class CSVFileReader :public FileReader {
public:
	CSVFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};