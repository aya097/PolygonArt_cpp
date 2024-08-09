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
			if (v.IsSelected)
			{
				Circle{ v.Pos,canvas.VertexOptions.Radius }
				.drawFrame(canvas.VertexOptions.Thinkness, 0, canvas.VertexOptions.SelectedColor);
			}
			else
			{
				Circle{ v.Pos,canvas.VertexOptions.Radius }
				.drawFrame(canvas.VertexOptions.Thinkness,0,canvas.VertexOptions.DefaultColor);
			}
		}
	}
}
