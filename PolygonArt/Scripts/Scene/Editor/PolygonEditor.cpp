#include "PolygonEditor.h"

void PolygonEditor::Edit(PolygonCanvas& canvas)
{
	// 操作の重複を避ける
	if (not EditVertex(canvas))
	{
		EditPolygon(canvas);
	}
	UpdateStatus(canvas);

}

bool PolygonEditor::EditVertex(PolygonCanvas& canvas)
{
	// なにかしら操作された？
	bool isOperated = false;
	// 頂点の選択/解除
	{
		auto v = canvas.GetVertices();
		bool isSelected = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,canvas.VertexOptions.Radius }.leftClicked())
			{
				if (selectedVertexIndices.contains(i))
					selectedVertexIndices.remove(i);
				else
					selectedVertexIndices << i;
				isSelected = true;
				isOperated = true;
				break;
			}
		}
		// 頂点以外を押していたら選択解除
		if (not isSelected && MouseL.down())
		{
			selectedVertexIndices.clear();
		}
	}
	// 選択解除
	{
		auto v = canvas.GetVertices();
		for (int i = 0; i < v.size(); i++)
		{
			if (Circle{ v[i].Pos,canvas.VertexOptions.Radius }.rightClicked())
			{
				selectedVertexIndices.remove_if([i](int n) { return n == i; });
				isOperated = true;
				break;
			}
		}
	}
	// Polygon 生成（頂点の操作に依存するため）
	{
		auto v = canvas.GetVertices();
		if (selectedVertexIndices.size() >= 3)
		{
			// todo : 色指定
			Triangle tri{ v[selectedVertexIndices[0]].Pos
			,v[selectedVertexIndices[1]].Pos
			,v[selectedVertexIndices[2]].Pos
			};
			// 生成される三角形の中に他の頂点があれば生成しない
			//if (std::none_of(v.begin(), v.end(), [&tri](Canvas::Vertex v)
			//	{
			//		return tri.contains(v.Pos);
			//	}))
			{
				canvas.AddPolygon(Canvas::Polygon{
					{selectedVertexIndices[0],selectedVertexIndices[1],selectedVertexIndices[2]}, canvas.polygonColor });
			}
			selectedVertexIndices.clear();
		}
	}

	return isOperated;
}

bool PolygonEditor::EditPolygon(PolygonCanvas& canvas)
{
	// なにかしら操作された？
	bool isOperated = false;
	// Polygon の選択/解除
	{
		auto p = canvas.GetPolygons();
		auto v = canvas.GetVertices();
		for (int i = p.size() - 1; i >= 0; i--)
		{
			if (Triangle{ v[p[i].Index[0]].Pos,v[p[i].Index[1]].Pos, v[p[i].Index[2]].Pos }.leftClicked())
			{
				selectedPolyognIndex = selectedPolyognIndex == i ? -1 : i;
				isOperated = true;
				break;
			}
		}
	}
	// Polygon の削除
	{
		auto p = canvas.GetPolygons();
		auto v = canvas.GetVertices();
		for (int i = p.size() - 1; i >= 0; i--)
		{
			if (Triangle{ v[p[i].Index[0]].Pos,v[p[i].Index[1]].Pos, v[p[i].Index[2]].Pos }.rightClicked())
			{
				if (selectedPolyognIndex == i)
				{
					canvas.RemovePolygon(i);
					selectedPolyognIndex = -1;
				}
				isOperated = true;
				break;
			}
		}
	}
	return isOperated;

}

void PolygonEditor::UpdateStatus(PolygonCanvas& canvas)
{
	// Vertex の更新
	auto v = canvas.GetVertices();
	for (int i = 0; i < selectedVertexIndices.size(); i++)
	{
		canvas.ExchangeVertex(selectedVertexIndices[i], Canvas::Vertex{ v[selectedVertexIndices[i]].Pos,true });
	}

	// Polygon の更新
	auto p = canvas.GetPolygons();
	if (selectedPolyognIndex != -1)
	{
		Canvas::Polygon pol = p[selectedPolyognIndex];
		pol.IsSelected = true;
		canvas.ExchangePolygon(selectedPolyognIndex, pol);
	}
}
