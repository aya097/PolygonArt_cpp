#include "VertexDrawer.h"

void VertexDrawer::Draw(const PolygonCanvas& canvas)
{
	// Vertex の描画
	{
		for (Canvas::Vertex v : canvas.GetVertices())
		{
			Circle{ v.Pos,10 }.draw(Palette::Yellow);
		}
	}
}
