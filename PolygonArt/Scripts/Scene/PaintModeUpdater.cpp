#include "PaintModeUpdater.h"
#include <Siv3D.hpp>

void PaintModeUpdater::Init()
{
	//ShowOnlyVertex,
	//ShowOnlyPolygon,
	//ShowCanvas,
	//EditVertex,
	//EditPolygon,
	//CopyColor,
	//ApplyColor
	instructionTexts[PaintMode::EditVertex] = U"生成:左クリック。\n移動:左クリック長押し。\n削除:右クリック。";
	instructionTexts[PaintMode::EditPolygon] = U"生成:3つの頂点を選択。\n削除:左クリックで選択した後、右クリック。";
	instructionTexts[PaintMode::CopyColor] = U"ポリゴン上で右クリックすると、色をコピーできる。";
	instructionTexts[PaintMode::ApplyColor] = U"ポリゴン上で右クリックすると、色を塗ることができる。";
	instructionTexts[PaintMode::ShowOnlyVertex] = U"頂点のみ表示する。";
	instructionTexts[PaintMode::ShowOnlyPolygon] = U"ポリゴンのみ表示する。";
	instructionTexts[PaintMode::ShowCanvas] = U"頂点、ポリゴン両方を表示する。";
}

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


	// 機能説明
	int instructionBoxHeight = 100;
	int instructionBoxWidth = 350;
	Rect instructionBox
	{
		(int)(leftop + distance * 7).x,
		(int)(leftop + distance * 7).y,
		instructionBoxWidth,
		instructionBoxHeight
	};
	instructionBox.draw();
	if (instructionTexts.contains(paintMode))
	{
		instructionFont(instructionTexts[paintMode]).draw(instructionBox.stretched(-10), ColorF{ 0 });
	}
}

const PaintMode& PaintModeUpdater::GetPaintMode() const
{
	return paintMode;
}
