#pragma once
#include "Drawer.h"

class PolygonDrawer : public Drawer
{
public :
	void Draw(const PolygonCanvas& canvas) override;
};
