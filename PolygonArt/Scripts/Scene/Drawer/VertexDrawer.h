#pragma once
#include "Drawer.h"

class VertexDrawer : public Drawer
{
public :
	VertexDrawer() {};
	VertexDrawer(std::shared_ptr<Drawer> drawer) : Drawer(drawer){};
	void Draw(const PolygonCanvas& canvas) override;
private:
	int radius = 10;
};
