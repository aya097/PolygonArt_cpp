#pragma once
#include "../Canvas/PolygonCanvas.h"

class FileWriter
{
public:
	void Write(const PolygonCanvas& canvas);
private:
	Optional<FilePath> path;
};
