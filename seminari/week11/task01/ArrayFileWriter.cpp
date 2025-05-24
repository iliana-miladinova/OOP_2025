#include "ArrayFileWriter.h"

ArrayFileWriter::ArrayFileWriter(const MyString& fileName) :FileWriter(fileName) {

}

void ArrayFileWriter::write(const int* arr, size_t size) const{
	std::ofstream ofs(fileName.c_str());

	if (!ofs.is_open()) {
		throw std::runtime_error("Could not open file for writing");
	}

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) {
			ofs << arr[i];
		}
		else
		{
			ofs << arr[i] << " ";
		}
	}
	ofs.close();
}