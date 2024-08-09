#include "DrawerSelector.h"

DrawerSelector::DrawerSelector()
{
	drawers[PaintMode::ShowOnlyPolygon] = std::make_shared<PolygonDrawer>();
	drawers[PaintMode::ShowOnlyVertex] = std::make_shared<VertexDrawer>();
	drawers[PaintMode::ShowCanvas] = std::make_shared<VertexDrawer>(std::make_shared<PolygonDrawer>());
	drawers[PaintMode::EditVertex] = std::make_shared<VertexDrawer>(std::make_shared<PolygonDrawer>());
	drawers[PaintMode::EditPolygon] = std::make_shared<VertexDrawer>(std::make_shared<PolygonDrawer>());
}

const std::shared_ptr<Drawer> DrawerSelector::SelectByPaintMode(const PaintMode& paintMode)
{
	return drawers[paintMode];
}
