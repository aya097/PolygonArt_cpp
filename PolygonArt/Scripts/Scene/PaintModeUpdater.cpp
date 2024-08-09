#include "PaintModeUpdater.h"

void PaintModeUpdater::Update()
{
	int width = 150;
	Vec2 leftop = Vec2{ 1530,20 };
	Vec2 distance = Vec2{ 0,50 };
	if (SimpleGUI::Button(U"頂点編集", leftop, width, (paintMode != PaintMode::EditVertex)))
	{
		paintMode = PaintMode::EditVertex;
	}
	if (SimpleGUI::Button(U"ポリゴン編集", leftop + distance, width, (paintMode != PaintMode::EditPolygon)))
	{
		paintMode = PaintMode::EditPolygon;
	}
	if (SimpleGUI::Button(U"スポイト", leftop + distance * 2, width, (paintMode != PaintMode::CopyColor)))
	{
		paintMode = PaintMode::CopyColor;
	}
	if (SimpleGUI::Button(U"色塗り", leftop + distance * 3, width, (paintMode != PaintMode::ApplyColor)))
	{
		paintMode = PaintMode::ApplyColor;
	}
	if (SimpleGUI::Button(U"頂点表示", leftop + distance * 4, width, (paintMode != PaintMode::ShowOnlyVertex)))
	{
		paintMode = PaintMode::ShowOnlyVertex;
	}
	if (SimpleGUI::Button(U"ポリゴン表示", leftop + distance * 5, width, (paintMode != PaintMode::ShowOnlyPolygon)))
	{
		paintMode = PaintMode::ShowOnlyPolygon;
	}
	if (SimpleGUI::Button(U"両方表示", leftop + distance * 6, width, (paintMode != PaintMode::ShowCanvas)))
	{
		paintMode = PaintMode::ShowCanvas;
	}
}

const PaintMode& PaintModeUpdater::GetPaintMode() const
{
	return paintMode;
}
