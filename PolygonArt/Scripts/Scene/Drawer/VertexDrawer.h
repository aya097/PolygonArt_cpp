#pragma once
#include "Drawer.h"

class VertexDrawer : public Drawer
{
public :
	void Draw(const PolygonCanvas& canvas) override;
private:
	int radius = 10;
};
