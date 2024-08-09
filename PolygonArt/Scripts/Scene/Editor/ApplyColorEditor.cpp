#include "ApplyColorEditor.h"

void ApplyColorEditor::Edit(PolygonCanvas& canvas)
{
	auto v = canvas.GetVertices();
	auto p = canvas.GetPolygons();
	for (int i = 0; i < p.size(); i++)
	{
		if (Triangle{ v[p[i].Index[0]].Pos,v[p[i].Index[1]].Pos, v[p[i].Index[2]].Pos }.leftClicked())
		{
			Canvas::Polygon pol = p[i];
			pol.Color = canvas.polygonColor;
			canvas.ExchangePolygon(i, pol);
			break;
		}
	}
}
