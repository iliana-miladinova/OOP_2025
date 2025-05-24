#pragma once
#include <fstream>
#include "MyString.h"

namespace HelperFunctions {
	size_t getFileSize(std::ifstream& ifs);
	size_t getCharCount(std::ifstream& ifs, char ch);
	MyString getFileExtension(const MyString& fileName);
}