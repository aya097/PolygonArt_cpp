#pragma once
#include "Drawer.h"

class PolygonDrawer : public Drawer
{
public :
	PolygonDrawer() {};
	PolygonDrawer(std::shared_ptr<Drawer> drawer) : Drawer(drawer) {};
	void Draw(const PolygonCanvas& canvas) override;
};
