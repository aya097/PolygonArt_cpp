#pragma once
#include "Editor.h"

class VertexEditor final: public Editor
{
public :
	void Edit(PolygonCanvas& canvas) override;
private:
	int SelectedVertexIndex = -1;
	int radius = 10;
};
