#pragma once
#include "../../Canvas/PolygonCanvas.h"

class Drawer
{
public:
	virtual void Draw(const PolygonCanvas& canvas) = 0;
	virtual ~Drawer() {};
};
