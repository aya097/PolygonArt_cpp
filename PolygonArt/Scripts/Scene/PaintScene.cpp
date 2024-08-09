#include "PaintScene.h"

void PaintScene::Init()
{
	canvas.AddVertex(Canvas::Vertex{ Point{ 100,100 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 200,300 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 300,100 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 400,300 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 500,100 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 600,300 } });
	canvas.AddPolygon(Canvas::Polygon{ {1,2,3},Palette::Red});
	/*canvas.AddPolygon(Canvas::Polygon{ {2,3,4},Palette::Blue });
	canvas.AddPolygon(Canvas::Polygon{ {4,5,1},Palette::Green });*/

	//Print << canvas.GetVertices().map([](Canvas::Vertex v) { return v.Pos; });
	//Print << canvas.GetPolygons().map([](Canvas::Polygon p) { return p.Index; });


	canvasRect = Rect{ 20,20,1500,1040 };
	Scene::SetBackground(ColorF{0.9});
}

void PaintScene::Update()
{
	//ClearPrint();
	paintModeUpdater.Update();
	Print << (int)paintModeUpdater.GetPaintMode();
	if (canvasRect.mouseOver())
		editSelector.SelectByPaintMode(PaintMode::EditVertex)->Edit(canvas);
}

void PaintScene::Draw()
{
	// キャンバスの描画
	{
		canvasRect.draw(Palette::White);
	}
	drawSelector.SelectByPaintMode(PaintMode::EditPolygon)->Draw(canvas);
}
