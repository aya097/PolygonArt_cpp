#pragma once
#include "Drawer.h"

class PolygonDrawer : public Drawer
{
public :
	PolygonDrawer() {};
	PolygonDrawer(std::unique_ptr<Drawer> drawer) : Drawer(std::move(drawer)) {};
	void Draw(const PolygonCanvas& canvas) override;
};
