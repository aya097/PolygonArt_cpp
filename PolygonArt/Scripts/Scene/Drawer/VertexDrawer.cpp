#include "VertexDrawer.h"

void VertexDrawer::Draw(const PolygonCanvas& canvas)
{
	// 所有している Drawer の描画
	if (drawer)
	{
		drawer->Draw(canvas);
	}

	// Vertex の描画
	{
		for (Canvas::Vertex v : canvas.GetVertices())
		{
			Circle{ v.Pos,10 }.draw(Palette::Yellow);
		}
	}
}
