#pragma once
#include "FileReader.h"
#include "FileWriter.h"

class FileFactory {
public:
	static FileReader* fileReaderFactory(const MyString& fileName);
	static FileWriter* fileWriterFactory(const MyString& fileName);
};