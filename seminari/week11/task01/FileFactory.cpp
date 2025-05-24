#include "FileFactory.h"
#include "ArrayFileReader.h"
#include "BinaryFileReader.h"
#include "CSVFileReader.h"
#include "ArrayFileWriter.h"
#include "BinaryFileWriter.h"
#include "CSVFileWriter.h"

FileReader* FileFactory::fileReaderFactory(const MyString& fileName) {
	MyString extension = HelperFunctions::getFileExtension(fileName);
	if (extension==".arr") {
		return new ArrayFileReader(fileName);
	}
	else if (extension==".dat")
	{
		return new BinaryFileReader(fileName);
	}
	else if (extension==".csv")
	{
		return new CSVFileReader(fileName);
	}
	else {
		throw std::exception("Invalid format");
	}
}

FileWriter* FileFactory::fileWriterFactory(const MyString& fileName) {
	MyString extension = HelperFunctions::getFileExtension(fileName);
	if (extension == ".arr") {
		return new ArrayFileWriter(fileName);
	}
	else if (extension == ".dat") {
		return new BinaryFileWriter(fileName);
	}
	else if (extension==".csv")
	{
		return new CSVFileWriter(fileName);
	}
	else {
		throw std::exception("Invalid format");
	}
}