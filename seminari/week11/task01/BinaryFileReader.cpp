#include "BinaryFileReader.h"

BinaryFileReader::BinaryFileReader(const MyString& fileName) :FileReader(fileName) {

}

void BinaryFileReader::read(int*& arr, size_t& size) const {
	std::ifstream ifs(fileName.c_str(), std::ios::binary);
	
	if (!ifs.is_open()) {
		throw std::runtime_error("Could not open file for reading");
	}

	delete[] arr;
	size_t fileSize = HelperFunctions::getFileSize(ifs);
	size = fileSize / sizeof(int);

	arr = new int[size];
	ifs.read((char*)arr, fileSize);
	ifs.close();
}