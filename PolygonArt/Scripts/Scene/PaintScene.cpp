#include "PaintScene.h"

void PaintScene::Init()
{
	canvasRect = Rect{ 20,20,1500,1040 };
	Scene::SetBackground(ColorF{0.9});
}

void PaintScene::Update()
{
	paintModeUpdater.Update();
	colorPaletteUpdater.Update();
	fileUpdater.Update(canvas);

	// Select状態の初期化
	canvas.FillIsSelected(false);

	// PaintMode に応じた処理
	if (canvasRect.mouseOver())
		editSelector.SelectByPaintMode(paintModeUpdater.GetPaintMode())->Edit(canvas);
}

void PaintScene::Draw()
{
	// キャンバスの描画
	{
		canvasRect.draw(Palette::White);
	}

	
	// PaintMode に応じた処理
	drawSelector.SelectByPaintMode(paintModeUpdater.GetPaintMode())->Draw(canvas);
}

PaintScene::~PaintScene()
{
	FileWriter f;
	f.Write(canvas);
}
