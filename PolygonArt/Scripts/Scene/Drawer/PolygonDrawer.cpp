﻿#include "PolygonDrawer.h"

void PolygonDrawer::Draw(const PolygonCanvas& canvas)
{
	// 所有している Drawer の描画
	if (drawer)
	{
		drawer->Draw(canvas);
	}

	// Polygon の描画
	{
		auto v = canvas.GetVertices();
		for (Canvas::Polygon p : canvas.GetPolygons())
		{
			if (p.IsSelected)
			{
				
				Triangle{ v[p.Index[0]].Pos,v[p.Index[1]].Pos, v[p.Index[2]].Pos }
					.draw(p.Color)
					.drawFrame(canvas.PolygonOptions.Thinckness, 0, canvas.PolygonOptions.SlectedEdgeColor);
			}
			else
			{
				Triangle{ v[p.Index[0]].Pos,v[p.Index[1]].Pos, v[p.Index[2]].Pos }.draw(p.Color);
			}
		}
	}
}
