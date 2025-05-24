#pragma once
#include <fstream>
#include "FileWriter.h"

class CSVFileWriter :public FileWriter {
public:
	CSVFileWriter(const MyString& fileName);
	void write(const int* arr, size_t size) const override;
};