# include <Siv3D.hpp>
#include "Scripts/Canvas/PolygonCanvas.h"

void Main()
{
	PolygonCanvas canvas;
	canvas.AddVertex(Canvas::Vertex{ Point{ 1,1 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 2,1 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 3,1 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 4,1 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 5,1 } });
	canvas.AddVertex(Canvas::Vertex{ Point{ 6,1 } });
	canvas.AddPolygon(Canvas::Polygon{ {1,2,3},Palette::Black });
	canvas.AddPolygon(Canvas::Polygon{ {2,3,4},Palette::Black });
	canvas.AddPolygon(Canvas::Polygon{ {4,5,1},Palette::Black });

	Print << canvas.GetVertices().map([](Canvas::Vertex v) { return v.Pos; });
	Print << canvas.GetPolygons().map([](Canvas::Polygon p) { return p.Index; });

	canvas.RemoveVertex(1);

	Print << canvas.GetVertices().map([](Canvas::Vertex v) { return v.Pos; });
	Print << canvas.GetPolygons().map([](Canvas::Polygon p) { return p.Index; });

	while (System::Update())
	{

	}
}
