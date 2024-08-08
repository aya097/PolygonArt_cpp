#include "PaintScene.h"

void PaintScene::Init()
{
	//canvas.AddVertex(Canvas::Vertex{ Point{ 100,100 } });
	//canvas.AddVertex(Canvas::Vertex{ Point{ 200,300 } });
	//canvas.AddVertex(Canvas::Vertex{ Point{ 300,100 } });
	//canvas.AddVertex(Canvas::Vertex{ Point{ 400,300 } });
	//canvas.AddVertex(Canvas::Vertex{ Point{ 500,100 } });
	//canvas.AddVertex(Canvas::Vertex{ Point{ 600,300 } });
	//canvas.AddPolygon(Canvas::Polygon{ {1,2,3},Palette::Red});
	///*canvas.AddPolygon(Canvas::Polygon{ {2,3,4},Palette::Blue });
	//canvas.AddPolygon(Canvas::Polygon{ {4,5,1},Palette::Green });*/

	Print << canvas.GetVertices().map([](Canvas::Vertex v) { return v.Pos; });
	Print << canvas.GetPolygons().map([](Canvas::Polygon p) { return p.Index; });


	canvasRect = Rect{ 50,50,1500,1000 };
}

void PaintScene::Update()
{
	vertexEditor.Edit(canvas);
}

void PaintScene::Draw()
{
	// キャンバスの描画
	{
		canvasRect.draw(Palette::White);
	}

	// Vertex の描画
	{
		for (Canvas::Vertex v : canvas.GetVertices())
		{
			Circle{ v.Pos,10 }.draw(Palette::Yellow);
		}
	}

	// Polygon の描画
	{
		auto v = canvas.GetVertices();

		for (Canvas::Polygon p : canvas.GetPolygons())
		{
			Triangle{ v[p.Index[0]].Pos,v[p.Index[1]].Pos, v[p.Index[2]].Pos }.draw(p.Color);
		}
	}
}

const PaintOptions PaintScene::PaintOptionSelector(PaintMode paintMode) const
{
	PaintOptions paintOption{ true,true };
	return paintOption;
}
