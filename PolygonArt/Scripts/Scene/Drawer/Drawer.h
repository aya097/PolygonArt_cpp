#pragma once
#include <memory>
#include "../../Canvas/PolygonCanvas.h"

class Drawer
{
public:
	Drawer() {};
	Drawer(std::shared_ptr<Drawer> drawer) :drawer(drawer) {};
	virtual void Draw(const PolygonCanvas& canvas) = 0;
	virtual ~Drawer() {};
protected:
	std::shared_ptr<Drawer> drawer;
};
