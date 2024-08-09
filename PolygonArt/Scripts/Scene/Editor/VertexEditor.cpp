#include "VertexEditor.h"

void VertexEditor::Edit(PolygonCanvas& canvas)
{
	// 頂点の選択
	{
		auto v = canvas.GetVertices();
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,radius }.leftClicked())
			{
				SelectedVertexIndex = i;
				break;
			}
		}
	}
	// 頂点の移動
	{
		auto v = canvas.GetVertices();
		if (SelectedVertexIndex != -1 && MouseL.pressed())
		{
			v[SelectedVertexIndex].Pos = Cursor::Pos();
		}
		else SelectedVertexIndex = -1;
	}
	// 頂点の削除
	{
		auto v = canvas.GetVertices();
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,radius }.rightClicked())
			{
				canvas.RemoveVertex(i);
				break;
			}
		}
	}
	// 頂点の追加
	{
		if (SelectedVertexIndex == -1 && MouseL.down())
		{
			canvas.AddVertex(Canvas::Vertex{ Cursor::Pos() });
		}
	}
	// 状態の更新
	{
		auto v = canvas.GetVertices();
		if (SelectedVertexIndex != -1)
		{
			v[SelectedVertexIndex].IsSelected = true;
		}
	}
}
