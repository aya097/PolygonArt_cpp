#pragma once
#include "../PaintParams.h"
#include "../Drawer/Drawer.h"
#include "../Drawer/VertexDrawer.h"
#include "../Drawer/PolygonDrawer.h"

class DrawerSelector
{
public:
	DrawerSelector();
	const std::shared_ptr<Drawer> SelectByPaintMode(const PaintMode& paintMode);
private:
	std::unordered_map<PaintMode, std::shared_ptr<Drawer>> drawers;
};
