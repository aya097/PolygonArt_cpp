#include "CopyColorEditor.h"

void CopyColorEditor::Edit(PolygonCanvas& canvas)
{
	auto v = canvas.GetVertices();
	auto p = canvas.GetPolygons();
	for (int i = p.size() - 1; i >= 0; i--)
	{
		if (Triangle{ v[p[i].Index[0]].Pos,v[p[i].Index[1]].Pos, v[p[i].Index[2]].Pos }.leftClicked())
		{
			canvas.polygonColor = p[i].Color;
			break;
		}
	}
}
