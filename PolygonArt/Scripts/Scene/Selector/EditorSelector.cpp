#include "EditorSelector.h"

EditorSelector::EditorSelector()
{
	editors[PaintMode::ShowOnlyPolygon] = std::make_shared<NoneEditor>();
	editors[PaintMode::ShowOnlyVertex] = std::make_shared<NoneEditor>();
	editors[PaintMode::ShowCanvas] = std::make_shared<NoneEditor>();
	editors[PaintMode::EditVertex] = std::make_shared<VertexEditor>();
	editors[PaintMode::EditPolygon] = std::make_shared<PolygonEditor>();
	editors[PaintMode::CopyColor] = std::make_shared<NoneEditor>();
	editors[PaintMode::ApplyColor] = std::make_shared<NoneEditor>();
}

const std::shared_ptr<Editor> EditorSelector::SelectByPaintMode(const PaintMode& paintMode)
{
	return editors[paintMode];
}

