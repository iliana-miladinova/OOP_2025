#include "CSVFileReader.h"

CSVFileReader::CSVFileReader(const MyString& fileName) :FileReader(fileName) {

}

void CSVFileReader::read(int*& arr, size_t& size) const {
	std::ifstream ifs(fileName.c_str());

	if (!ifs.is_open()) {
		throw std::runtime_error("Could not open file for reading");
	}

	delete[] arr;
	size = HelperFunctions::getCharCount(ifs, ',') + 1;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		ifs >> arr[i];
		ifs.ignore(); //in order to skip the commas
	}
	ifs.close();
}