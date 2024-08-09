#pragma once
#include "Drawer.h"

class VertexDrawer : public Drawer
{
public :
	VertexDrawer() {};
	VertexDrawer(std::unique_ptr<Drawer> drawer) : Drawer(std::move(drawer)){};
	void Draw(const PolygonCanvas& canvas) override;
private:
	int radius = 10;
};
