#pragma once
#include <memory>
#include "../../Canvas/PolygonCanvas.h"

class Drawer
{
public:
	Drawer() {};
	Drawer(std::unique_ptr<Drawer> drawer) :drawer(std::move(drawer)) {};
	virtual void Draw(const PolygonCanvas& canvas) = 0;
	virtual ~Drawer() {};
protected:
	std::unique_ptr<Drawer> drawer;
};
