#pragma once
#include "FileWriter.h"

class FileUpdater
{
public:
	void Update(PolygonCanvas& canvas);
private:
	FileWriter fileWriter;
};

