#pragma once
#include "FileWriter.h"
#include "FileReader.h"

class FileUpdater
{
public:
	void Update(PolygonCanvas& canvas);
private:
	FileWriter fileWriter;
	FileReader fileReader;
};

