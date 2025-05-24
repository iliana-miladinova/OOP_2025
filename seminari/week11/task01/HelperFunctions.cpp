#include "HelperFunctions.h"

size_t HelperFunctions::getFileSize(std::ifstream& ifs) {
	size_t curr = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(curr);
	return size;
}

size_t HelperFunctions::getCharCount(std::ifstream& ifs, char ch) {
	int count = 0;
	size_t currPos = ifs.tellg();
	ifs.seekg(0);

	while (true) {
		char currChar = ifs.get();
		if (ifs.eof()) {
			break;
		}
		if (currChar == ch) {
			count++;
		}
	}
	ifs.clear();
	ifs.seekg(currPos);
	return count;
}

MyString HelperFunctions::getFileExtension(const MyString& fileName) {
	int start = fileName.len() - 1;
	for (int i = start; i >= 0; i--)
	{
		if (fileName[i]=='.')
		{
			break;
		}
		start--;
	}
	return fileName.substr(start, fileName.len() - start);
	
}