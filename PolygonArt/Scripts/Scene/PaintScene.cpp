#include "PaintScene.h"

void Attack(PolygonCanvas& canvas, Point impact, Point pos, int width, bool Tate)
{
	auto v = canvas.GetVertices();
	for (int i = 0; i < v.size(); i++)
	{
		if (Tate)
		{
			if ((v[i].Pos.x - pos.x) * (v[i].Pos.x - pos.x) < width * width)
			{
				canvas.ExchangeVertex(i, Canvas::Vertex{ v[i].Pos + impact });
			}
		}
		else
		{
			if ((v[i].Pos.y - pos.y) * (v[i].Pos.y - pos.y) < width * width)
			{
				canvas.ExchangeVertex(i, Canvas::Vertex{ v[i].Pos + impact });
			}
		}
	}
}

void PaintScene::Init()
{
	canvasRect = Rect{ 20,20,1500,1040 };
	Scene::SetBackground(ColorF{ 0.9 });
}

void PaintScene::Update()
{
	if (SimpleGUI::Button(U"攻撃", Vec2{ 1600,100 }))
	{
		Attack(canvas, Point{ 0,-75 }, Point{ 300,0 }, 80, true);
		Attack(canvas, Point{ 75,0 }, Point{ 0,600 }, 80, false);
		Attack(canvas, Point{ 0,75 }, Point{ 500,0 }, 80, true);
		Attack(canvas, Point{ 75,0 }, Point{ 0,300 }, 80, false);

		Attack(canvas, Point{ 0,75 }, Point{ 300,0 }, 80, true);
		Attack(canvas, Point{ -75,0 }, Point{ 0,600 }, 80, false);
		Attack(canvas, Point{ 0,-75 }, Point{ 500,0 }, 80, true);
		Attack(canvas, Point{ -75,0 }, Point{ 0,300 }, 80, false);
	}



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
