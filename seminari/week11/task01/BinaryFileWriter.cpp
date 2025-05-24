#include "BinaryFileWriter.h"

BinaryFileWriter::BinaryFileWriter(const MyString& fileName) :FileWriter(fileName) {

}

void BinaryFileWriter::write(const int* arr, size_t size) const {
	std::ofstream ofs(fileName.c_str(), std::ios::binary);

	if (!ofs.is_open()) {
		throw std::runtime_error("Could not open file for writing");
	}

	ofs.write((const char*)arr, size * sizeof(int));
	ofs.close();
}